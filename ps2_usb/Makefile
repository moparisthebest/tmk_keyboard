#
# Makefile for PJRC Teensy
#


# Target file name (without extension).
TARGET = ps2_usb_pjrc

# Directory common source filess exist
COMMON_DIR = ..

# Directory keyboard dependent files exist
TARGET_DIR = .

# keyboard dependent files
TARGET_SRC =	main_pjrc.c \
		keymap.c \
		matrix.c \
		led.c \
		ps2.c

CONFIG_H = config_pjrc.h


# MCU name, you MUST set this to match the board you are using
# type "make clean" after changing this, so all files will be rebuilt
#MCU = at90usb162       # Teensy 1.0
#MCU = atmega32u4       # Teensy 2.0
#MCU = at90usb646       # Teensy++ 1.0
MCU = at90usb1286      # Teensy++ 2.0


# Processor frequency.
#   Normally the first thing your program should do is set the clock prescaler,
#   so your program will run at the correct speed.  You should also set this
#   variable to same clock speed.  The _delay_ms() macro uses this, and many
#   examples use this variable to calculate timings.  Do not add a "UL" here.
F_CPU = 16000000


# Build Options
#   comment out to disable the options.
#
MOUSEKEY_ENABLE = yes	# Mouse keys
USB_EXTRA_ENABLE = yes	# Audio control and System control
USB_NKRO_ENABLE = yes	# USB Nkey Rollover



#---------------- Programming Options --------------------------
PROGRAM_CMD = teensy_loader_cli -mmcu=$(MCU) -w -v $(TARGET).hex



include $(COMMON_DIR)/Makefile.pjrc
include $(COMMON_DIR)/Makefile.common
