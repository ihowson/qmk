/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#define USE_MATRIX_I2C

/* Select hand configuration */

#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#define SSD1306OLED

#define DEBUG_MATRIX_SCAN_RATE 1
#define CONSOLE_ENABLE 1

#undef DEBOUNCE
#define DEBOUNCE 1

#define USE_SERIAL_PD2

#define FORCE_NKRO

#define USB_POLLING_INTERVAL_MS 1

#define TAPPING_FORCE_HOLD
#define TAPPING_TERM 100

// #undef RGBLED_NUM
// #define RGBLIGHT_ANIMATIONS
// #define RGBLIGHT_EFFECT_BREATHING
// #define RGBLIGHT_EFFECT_RAINBOW_MOOD
// #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
// #define RGBLIGHT_EFFECT_SNAKE
// #define RGBLED_NUM 27
// #define RGBLED_NUM 9
// #define RGBLED_SPLIT {8, 1}
// #define RGBLIGHT_LIMIT_VAL 120
// #define RGBLIGHT_HUE_STEP 10
// #define RGBLIGHT_SAT_STEP 17
// #define RGBLIGHT_VAL_STEP 17

// #define RGBLIGHT_LAYERS

// #define RGBLIGHT_SLEEP
// #define RGBLIGHT_SPLIT

// from https://www.reddit.com/r/olkb/comments/72u8ou/qmk_mouse_keys_rock/
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0
