# MCU name
MCU = atmega32u4

# Bootloader selection
#   Teensy       halfkay
#   Pro Micro    caterina
#   Atmel DFU    atmel-dfu
#   LUFA DFU     lufa-dfu
#   QMK DFU      qmk-dfu
#   ATmega32A    bootloadHID
#   ATmega328P   USBasp
BOOTLOADER = caterina

# Build Options
#   change to "no" to disable the options, or define them in the Makefile in
#   the appropriate keymap folder that will get included automatically
#
BOOTMAGIC_ENABLE = no       # Virtual DIP switch configuration
MOUSEKEY_ENABLE = no       # Mouse keys
EXTRAKEY_ENABLE = no       # Audio control and System control
# CONSOLE_ENABLE = no         # Console for debug
# CONSOLE_ENABLE = yes         # Console for debug
#OLED_DRIVER_ENABLE = yes
COMMAND_ENABLE = no        # Commands for debug and configuration
# NKRO_ENABLE = no            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
NKRO_ENABLE = yes            # Nkey Rollover - if this doesn't work, see here: https://github.com/tmk/tmk_keyboard/wiki/FAQ#nkro-doesnt-work
BACKLIGHT_ENABLE = no      # Enable keyboard backlight functionality
MIDI_ENABLE = no            # MIDI controls
AUDIO_ENABLE = no           # Audio output on port C6
UNICODE_ENABLE = no         # Unicode
BLUETOOTH_ENABLE = no       # Enable Bluetooth with the Adafruit EZ-Key HID
#RGBLIGHT_ENABLE = yes       # Enable WS2812 RGB underlight.
RGBLIGHT_ENABLE = no       # Enable WS2812 RGB underlight.
# Do not enable SLEEP_LED_ENABLE. it uses the same timer as BACKLIGHT_ENABLE
SLEEP_LED_ENABLE = no    # Breathing sleep LED during USB suspend

CUSTOM_MATRIX = yes

SRC += i2c.c
SRC += serial.c

# A workaround until #7089 is merged.
#   serial.c must not be compiled with the -lto option.
#   The current LIB_SRC has a side effect with the -fno-lto option, so use it.
LIB_SRC += serial.c

# if firmware size over limit, try this option
# CFLAGS += -flto

DEFAULT_FOLDER = spooney/rev1
