#ifndef CONFIG_H
#define CONFIG_H

/* controller configuration */
#include "controller_teensy.h"

#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6512
#define MANUFACTURER    moparisthebest
#define PRODUCT         QWERTY/Dvorak converter
#define DESCRIPTION     convert PS/2 keyboard to USB


/* matrix size */
#define MATRIX_ROWS 32  // keycode bit: 3-0
#define MATRIX_COLS 8   // keycode bit: 6-4


/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (BIT_LSHIFT | BIT_RSHIFT) \
)

/* key combination for command, reverts to defined layout */
#define IS_SHORTCUT() ( \
    keyboard_report->mods & BIT_LCTRL \
)
#define SHORTCUT_LAYOUT 1

/* key combination for command */
#define IS_SWAP() ( \
    keyboard_report->mods == (BIT_LCTRL | BIT_LSHIFT | BIT_RCTRL | BIT_RSHIFT) \
)

/* mouse keys */
#ifdef MOUSEKEY_ENABLE
#   define MOUSEKEY_DELAY_TIME 255
#endif


/* PS/2 lines */
#define PS2_CLOCK_PORT  PORTD
#define PS2_CLOCK_PIN   PIND
#define PS2_CLOCK_DDR   DDRD
#define PS2_CLOCK_BIT   3
#define PS2_DATA_PORT   PORTE
#define PS2_DATA_PIN    PINE
#define PS2_DATA_DDR    DDRE
#define PS2_DATA_BIT    0

#endif
