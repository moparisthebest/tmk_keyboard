/*
 * Key codes from HID Keyboard/Keypad Page
 * http://www.usb.org/developers/devclass_docs/Hut1_12.pdf
 *
 * Based on Keyboard Upgrade v0.3.0 http://github.com/rhomann/kbupgrade
 */
/*
 * Keyboard Upgrade -- Firmware for homebrew computer keyboard controllers.
 * Copyright (C) 2009  Robert Homann
 *
 * Based on RUMP (http://mg8.org/rump/), Copyright (C) 2008  Chris Lee
 *
 * Based on c64key (http://symlink.dk/projects/c64key/),
 * Copyright (C) 2006-2007  Mikkel Holm Olsen
 *
 * Based on HID-Test by Christian Starkjohann, Objective Development
 *
 * This file is part of the Keyboard Upgrade package.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the Keyboard Upgrade package; if not, write to the
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA  02110-1301  USA
 */
#ifndef USB_KEYCODES_H
#define USB_KEYCODES_H


#define IS_ERROR(code)           (KB_ROLL_OVER <= (code) && (code) <= KB_UNDEFINED)
#define IS_KEY(code)             (KB_A         <= (code) && (code) <= KB_KP_HEXADECIMAL)
#define IS_MOD(code)             (KB_LCTRL     <= (code) && (code) <= KB_RGUI)
#define IS_FN(code)              (KB_FN0       <= (code) && (code) <= KB_FN7)
#define IS_MOUSEKEY(code)        (KB_MS_UP     <= (code) && (code) <= KB_MS_WH_RIGHT)
#define IS_MOUSEKEY_MOVE(code)   (KB_MS_UP     <= (code) && (code) <= KB_MS_RIGHT)
#define IS_MOUSEKEY_BUTTON(code) (KB_MS_BTN1   <= (code) && (code) <= KB_MS_BTN5)
#define IS_MOUSEKEY_WHEEL(code)  (KB_MS_WH_UP  <= (code) && (code) <= KB_MS_WH_RIGHT)

#define MOD_BIT(code) (1<<((code) & 0x07))
#define FN_BIT(code)  (1<<((code) - KB_FN0))


//
// Short names
//
#define KB_LCTL KB_LCTRL
#define KB_RCTL KB_RCTRL
#define KB_LSFT KB_LSHIFT
#define KB_RSFT KB_RSHIFT
#define KB_ESC  KB_ESCAPE
#define KB_BSPC KB_BSPACE
#define KB_ENT  KB_ENTER
#define KB_DEL  KB_DELETE
#define KB_INS  KB_INSERT
#define KB_CAPS KB_CAPSLOCK
#define KB_RGHT KB_RIGHT
#define KB_PGDN KB_PGDOWN
#define KB_PSCR KB_PSCREEN
#define KB_SLCK KB_SCKLOCK
#define KB_BRK  KB_BREAK
#define KB_NLCK KB_NUMLOCK
#define KB_SPC  KB_SPACE
#define KB_MINS KB_MINUS
#define KB_EQL  KB_EQUAL
#define KB_GRV  KB_GRAVE
#define KB_RBRC KB_RBRACKET
#define KB_LBRC KB_LBRACKET
#define KB_COMM KB_COMMA
#define KB_BSLS KB_BSLASH
#define KB_SLSH KB_SLASH
#define KB_SCLN KB_SCOLON
#define KB_QUOT KB_QUOTE
#define KB_PWR  KB_POWER
#define KB_VOLU KB_VOLUP
#define KB_VOLD KB_VOLDOWN
#define KB_APP  KB_APPLICATION
#define KB_NUHS KB_NONUS_HASH
#define KB_NUBS KB_NONUS_BSLASH
// for Japanese
#define KB_RO   KB_INT1
#define KB_KANA KB_INT2
#define KB_JYEN KB_INT3
#define KB_HENK KB_INT4
#define KB_MHEN KB_INT5
#define KB_ZEHA KB_GRAVE
// Keypad
#define KB_P1   KB_KP_1
#define KB_P2   KB_KP_2
#define KB_P3   KB_KP_3
#define KB_P4   KB_KP_4
#define KB_P5   KB_KP_5
#define KB_P6   KB_KP_6
#define KB_P7   KB_KP_7
#define KB_P8   KB_KP_8
#define KB_P9   KB_KP_9
#define KB_P0   KB_KP_0
#define KB_PDOT KB_KP_DOT
#define KB_PSLS KB_KP_SLASH
#define KB_PAST KB_KP_ASTERISK
#define KB_PMNS KB_KP_MINUS
#define KB_PPLS KB_KP_PLUS
#define KB_PEQL KB_KP_EQUAL
#define KB_PENT KB_KP_ENTER
// Mousekey
#define KB_MS_U KB_MS_UP
#define KB_MS_D KB_MS_DOWN
#define KB_MS_L KB_MS_LEFT
#define KB_MS_R KB_MS_RIGHT
#define KB_BTN1 KB_MS_BTN1
#define KB_BTN2 KB_MS_BTN2
#define KB_BTN3 KB_MS_BTN3
#define KB_BTN4 KB_MS_BTN4
#define KB_BTN5 KB_MS_BTN5
#define KB_WH_U KB_MS_WH_UP
#define KB_WH_D KB_MS_WH_DOWN
#define KB_WH_L KB_MS_WH_LEFT
#define KB_WH_R KB_MS_WH_RIGHT


enum keycodes {
    KB_NO = 0,
    KB_ROLL_OVER,
    KB_POST_FAIL,
    KB_UNDEFINED,
    KB_A,
    KB_B,
    KB_C,
    KB_D,
    KB_E,
    KB_F,
    KB_G,
    KB_H,
    KB_I,
    KB_J,
    KB_K,
    KB_L,
    KB_M,       /* 0x10 */
    KB_N,
    KB_O,
    KB_P,
    KB_Q,
    KB_R,
    KB_S,
    KB_T,
    KB_U,
    KB_V,
    KB_W,
    KB_X,
    KB_Y,
    KB_Z,
    KB_1,
    KB_2,
    KB_3,       /* 0x20 */
    KB_4,
    KB_5,
    KB_6,
    KB_7,
    KB_8,
    KB_9,
    KB_0,
    KB_ENTER,
    KB_ESCAPE,
    KB_BSPACE,
    KB_TAB,
    KB_SPACE,
    KB_MINUS,
    KB_EQUAL,
    KB_LBRACKET,          /* [ */
    KB_RBRACKET,          /* ] */
    KB_BSLASH,            /* \ (and |) */
    KB_NONUS_HASH,        /* Non-US # and ~ */
    KB_SCOLON,            /* ; (and :) */
    KB_QUOTE,             /* ' and " */
    KB_GRAVE,             /* Grave accent and tilde */
    KB_COMMA,             /* , and < */
    KB_DOT,               /* . and > */
    KB_SLASH,             /* / and ? */
    KB_CAPSLOCK,
    KB_F1,
    KB_F2,
    KB_F3,
    KB_F4,
    KB_F5,
    KB_F6,
    KB_F7,      /* 0x40 */
    KB_F8,
    KB_F9,
    KB_F10,
    KB_F11,
    KB_F12,
    KB_PSCREEN,
    KB_SCKLOCK,
    KB_BREAK,
    KB_INSERT,
    KB_HOME,
    KB_PGUP,
    KB_DELETE,
    KB_END,
    KB_PGDOWN,
    KB_RIGHT,
    KB_LEFT,    /* 0x50 */
    KB_DOWN,
    KB_UP,
    KB_NUMLOCK,
    KB_KP_SLASH,
    KB_KP_ASTERISK,
    KB_KP_MINUS,
    KB_KP_PLUS,
    KB_KP_ENTER,
    KB_KP_1,
    KB_KP_2,
    KB_KP_3,
    KB_KP_4,
    KB_KP_5,
    KB_KP_6,
    KB_KP_7,
    KB_KP_8,       /* 0x60 */
    KB_KP_9,
    KB_KP_0,
    KB_KP_DOT,
    KB_NONUS_BSLASH,      /* Non-US \ and | */
    KB_APPLICATION,
    KB_POWER,
    KB_KP_EQUAL,
    KB_F13,
    KB_F14,
    KB_F15,
    KB_F16,
    KB_F17,
    KB_F18,
    KB_F19,
    KB_F20,
    KB_F21,     /* 0x70 */
    KB_F22,
    KB_F23,
    KB_F24,
    KB_EXECUTE,
    KB_HELP,
    KB_MENU,
    KB_SELECT,
    KB_STOP,
    KB_AGAIN,
    KB_UNDO,
    KB_CUT,
    KB_COPY,
    KB_PASTE,
    KB_FIND,
    KB_MUTE,
    KB_VOLUP,   /* 0x80 */
    KB_VOLDOWN,
    KB_LOCKING_CAPS,      /* locking Caps Lock */
    KB_LOCKING_NUM,       /* locking Num Lock */
    KB_LOCKING_SCROLL,    /* locking Scroll Lock */
    KB_KP_COMMA,
    KB_KP_EQUAL_AS400,       /* equal sign on AS/400 */
    KB_INT1,
    KB_INT2,
    KB_INT3,
    KB_INT4,
    KB_INT5,
    KB_INT6,
    KB_INT7,
    KB_INT8,
    KB_INT9,
    KB_LANG1,    /* 0x90 */
    KB_LANG2,
    KB_LANG3,
    KB_LANG4,
    KB_LANG5,
    KB_LANG6,
    KB_LANG7,
    KB_LANG8,
    KB_LANG9,
    KB_ALT_ERASE,
    KB_SYSREQ,
    KB_CANCEL,
    KB_CLEAR,
    KB_PRIOR,
    KB_RETURN,
    KB_SEPARATOR,
    KB_OUT,
    KB_OPER,
    KB_CLEAR_AGAIN,
    KB_CRSEL,
    KB_EXSEL,

    KB_KP_00 = 0xB0,
    KB_KP_000,
    KB_THOUSANDS_SEPARATOR,
    KB_DECIMAL_SEPARATOR,
    KB_CURRENCY_UNIT,
    KB_CURRENCY_SUB_UNIT,
    KB_KP_LPAREN,
    KB_KP_RPAREN,
    KB_KP_LCBRACKET,         /* { */
    KB_KP_RCBRACKET,         /* } */
    KB_KP_TAB,
    KB_KP_BSPACE,
    KB_KP_A,
    KB_KP_B,
    KB_KP_C,
    KB_KP_D,
    KB_KP_E,
    KB_KP_F,
    KB_KP_XOR,
    KB_KP_HAT,
    KB_KP_PERC,
    KB_KP_LT,
    KB_KP_GT,
    KB_KP_AND,
    KB_KP_LAZYAND,
    KB_KP_OR,
    KB_KP_LAZYOR,
    KB_KP_COLON,
    KB_KP_HASH,
    KB_KP_SPACE,
    KB_KP_ATMARK,
    KB_KP_EXCLAMATION,
    KB_KP_MEM_STORE,
    KB_KP_MEM_RECALL,
    KB_KP_MEM_CLEAR,
    KB_KP_MEM_ADD,
    KB_KP_MEM_SUB,
    KB_KP_MEM_MUL,
    KB_KP_MEM_DIV,
    KB_KP_PLUS_MINUS,
    KB_KP_CLEAR,
    KB_KP_CLEAR_ENTRY,
    KB_KP_BINARY,
    KB_KP_OCTAL,
    KB_KP_DECIMAL,
    KB_KP_HEXADECIMAL,

    /* modifiers */
    KB_LCTRL = 0xE0,    /* 0x01 */
    KB_LSHIFT,          /* 0x02 */
    KB_LALT,            /* 0x04 */
    KB_LGUI,            /* 0x08 */
    KB_RCTRL,           /* 0x10 */
    KB_RSHIFT,          /* 0x20 */
    KB_RALT,            /* 0x40 */
    KB_RGUI,            /* 0x80 */

    /* extensions for internal use */
    KB_FN0 = 0xE8,
    KB_FN1,
    KB_FN2,
    KB_FN3,
    KB_FN4,
    KB_FN5,
    KB_FN6,
    KB_FN7,
    // Mousekey move
    KB_MS_UP = 0xF0,
    KB_MS_DOWN,
    KB_MS_LEFT,
    KB_MS_RIGHT,
    // Mousekey buttons
    KB_MS_BTN1 = 0xF4,
    KB_MS_BTN2,
    KB_MS_BTN3,
    KB_MS_BTN4,
    KB_MS_BTN5,
    // Mousekey wheel
    KB_MS_WH_UP,
    KB_MS_WH_DOWN,
    KB_MS_WH_LEFT,
    KB_MS_WH_RIGHT,
};

#endif /* USB_KEYCODES_H */
