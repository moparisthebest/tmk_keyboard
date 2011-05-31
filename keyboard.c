#include "keyboard.h"
#include "host.h"
#include "layer.h"
#include "matrix.h"
#include "led.h"
#include "usb_keycodes.h"
#include "timer.h"
#include "print.h"
#include "debug.h"
#include "command.h"
#ifdef MOUSEKEY_ENABLE
#include "mousekey.h"
#endif
#ifdef USB_EXTRA_ENABLE
#include <util/delay.h>
#endif


static uint8_t last_leds = 0;
static bool scroll_lock = false;


void keyboard_init(void)
{
    timer_init();
    matrix_init();
#ifdef PS2_MOUSE_ENABLE
    ps2_mouse_init();
#endif
}

void keyboard_proc(void)
{
    uint8_t fn_bits = 0;
#ifdef USB_EXTRA_ENABLE
    uint16_t consumer_code = 0;
#endif

    matrix_scan();

    if (matrix_is_modified()) {
        if (debug_matrix) matrix_print();
#ifdef DEBUG_LED
        // LED flash for debug
        DEBUG_LED_CONFIG;
        DEBUG_LED_ON;
#endif
    }

    if (matrix_has_ghost()) {
        // should send error?
        debug("matrix has ghost!!\n");
        return;
    }

    host_swap_keyboard_report();
    host_clear_keyboard_report();
    for (int row = 0; row < matrix_rows(); row++) {
        for (int col = 0; col < matrix_cols(); col++) {
            if (!matrix_is_on(row, col)) continue;
            //print("row,col: "); pdec(row); print(","); pdec(col); print("\n");
            uint8_t code = layer_get_keycode(row, col);
            //print("keycode: "); pdec(code); print("\n");
            if (code == KB_NO) {
                // do nothing
                print("KB_NO: "); pdec(row); print(","); pdec(col); print("\n");
            } else if (IS_MOD(code)) {
                host_add_mod_bit(MOD_BIT(code));
            } else if (IS_FN(code)) {
                fn_bits |= FN_BIT(code);
            }
#ifdef USB_EXTRA_ENABLE
            // System Control
            else if (code == KB_SYSTEM_POWER) {
#ifdef HOST_PJRC
                if (suspend && remote_wakeup) {
                    usb_remote_wakeup();
                } else {
                    host_system_send(SYSTEM_POWER_DOWN);
                }
#else
                host_system_send(SYSTEM_POWER_DOWN);
#endif
                host_system_send(0);
                _delay_ms(500);
            } else if (code == KB_SYSTEM_SLEEP) {
                host_system_send(SYSTEM_SLEEP);
                host_system_send(0);
                _delay_ms(500);
            } else if (code == KB_SYSTEM_WAKE) {
                host_system_send(SYSTEM_WAKE_UP);
                host_system_send(0);
                _delay_ms(500);
            }
            // Consumer Page
            else if (code == KB_AUDIO_MUTE) {
                consumer_code = AUDIO_MUTE;
            } else if (code == KB_AUDIO_VOL_UP) {
                consumer_code = AUDIO_VOL_UP;
            } else if (code == KB_AUDIO_VOL_DOWN) {
                consumer_code = AUDIO_VOL_DOWN;
            }
            else if (code == KB_MEDIA_NEXT_TRACK) {
                consumer_code = TRANSPORT_NEXT_TRACK;
            } else if (code == KB_MEDIA_PREV_TRACK) {
                consumer_code = TRANSPORT_PREV_TRACK;
            } else if (code == KB_MEDIA_STOP) {
                consumer_code = TRANSPORT_STOP;
            } else if (code == KB_MEDIA_PLAY_PAUSE) {
                consumer_code = TRANSPORT_PLAY_PAUSE;
            } else if (code == KB_MEDIA_SELECT) {
                consumer_code = AL_CC_CONFIG;
            }
            else if (code == KB_MAIL) {
                consumer_code = AL_EMAIL;
            } else if (code == KB_CALCULATOR) {
                consumer_code = AL_CALCULATOR;
            } else if (code == KB_MY_COMPUTER) {
                consumer_code = AL_LOCAL_BROWSER;
            }
            else if (code == KB_WWW_SEARCH) {
                consumer_code = AC_SEARCH;
            } else if (code == KB_WWW_HOME) {
                consumer_code = AC_HOME;
            } else if (code == KB_WWW_BACK) {
                consumer_code = AC_BACK;
            } else if (code == KB_WWW_FORWARD) {
                consumer_code = AC_FORWARD;
            } else if (code == KB_WWW_STOP) {
                consumer_code = AC_STOP;
            } else if (code == KB_WWW_REFRESH) {
                consumer_code = AC_REFRESH;
            } else if (code == KB_WWW_FAVORITES) {
                consumer_code = AC_BOOKMARKS;
            }
#endif
            else if (IS_KEY(code)) {
                host_add_key(code);
            }
#ifdef MOUSEKEY_ENABLE
            else if (IS_MOUSEKEY(code)) {
                mousekey_decode(code);
            }
#endif
            else {
                debug("ignore keycode: "); debug_hex(code); debug("\n");
            }
        }
    }

    layer_switching(fn_bits);
    uint8_t ret = command_proc();
    if (ret != 0 && ret != SCROLL_LOCK_TOGGLE) {
        _delay_ms(500);
        return;
    }

    if(ret == SCROLL_LOCK_TOGGLE){
        scroll_lock = !scroll_lock;
    }

    // TODO: should send only when changed from last report
    if (matrix_is_modified()) {
        host_send_keyboard_report();
#ifdef USB_EXTRA_ENABLE
        host_consumer_send(consumer_code);
#endif
#ifdef DEBUG_LED
        // LED flash for debug
        DEBUG_LED_CONFIG;
        DEBUG_LED_OFF;
#endif
    }

#ifdef MOUSEKEY_ENABLE
    mousekey_send();
#endif

#ifdef PS2_MOUSE_ENABLE
    // TODO: should comform new API
    if (ps2_mouse_read() == 0)
        ps2_mouse_usb_send();
#endif
        uint8_t current_leds = (scroll_lock || IS_SHORTCUT()) ? (host_keyboard_leds() | (1<<USB_LED_SCROLL_LOCK)) : host_keyboard_leds();
    if (last_leds != current_leds) {
        keyboard_set_leds(current_leds);
	    last_leds = current_leds;
        if(ret == SCROLL_LOCK_TOGGLE)
            _delay_ms(500);
    }
}

void keyboard_set_leds(uint8_t leds)
{
    led_set(leds);
}
