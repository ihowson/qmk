#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif



/*
#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif
*/

extern uint8_t is_master;

// enum layer_names {
#define _QWERTY 0
#define _RAISE 1
// #define _ADJUST 3

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   RAISE,
//   // ADJUST,
// };


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
// TODO: diagram doesn't match keymap
 * ,------------------------------------------------.             ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |             |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------+------'         ,---+------+------+------+------+------+------|
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  [   |  ]   |  \   |  END   |
 * |---------+-+-----+------+------+------+-------.                 |------+------+------+------+------+------|
 * |  Esc      |   A  |   S  |   D  |   F  |   G  |            |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |-----------+-+-----+------+------+------+--------.   |        [   |    |    ]  |------+------+------+------+------+------|
 * |   LShift    |   Z  |   X  |   C  |   V  |   B   |               -------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * |-----------+-------------------------------------|    /          /     \      \-----------------------------------------'
 * |   LCtrl   | RAISE |   LAlt   |   LGUI   | LUTIL |      /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 * `-------------------------------------------------'           '------''--------------------'
 */

[_QWERTY] = {
  // LEFT HALF
  { KC_GRAVE, KC_1,       KC_2,      KC_3,     KC_4,   KC_5,               KC_6, _______},
  {   KC_TAB, KC_Q,       KC_W,      KC_E,     KC_R,   KC_T,              KC_NO, _______},
  {   KC_ESC, KC_A,       KC_S,      KC_D,     KC_F,   KC_G,              KC_NO, _______},
  {  KC_LSFT, KC_NO,      KC_Z,      KC_X,     KC_C,   KC_V,               KC_B, _______},
  { KC_LCTRL, MO(_RAISE), KC_LALT,   KC_NO, KC_LGUI,   KC_NO, SGUI(KC_LBRACKET), _______},
  {  _______,    _______, _______, _______, _______, _______,           _______, _______},

  // RIGHT HALF
  // FIXME: put the right keymap here
  // FIXME: you changed the row/col count on right side
  // FIXME: this needs more columns, but you might just use the spare line on the left and use the same row/col mapping on both
  {           _______, KC_AUDIO_VOL_DOWN, KC_AUDIO_VOL_UP, KC_AUDIO_MUTE,    KC_END,   KC_PGDOWN,     _______, _______},
  {              KC_7,              KC_8,            KC_9,          KC_0,  KC_MINUS,    KC_EQUAL,   KC_BSPACE, KC_HOME},
  {              KC_Y,              KC_U,            KC_I,          KC_O,      KC_P, KC_LBRACKET, KC_RBRACKET, KC_BSLASH},
  {              KC_H,              KC_J,            KC_K,          KC_L, KC_SCOLON,    KC_QUOTE,    KC_ENTER, KC_PGUP},
  {           _______,              KC_N,            KC_M,      KC_COMMA,    KC_DOT,    KC_SLASH,   KC_RSHIFT, KC_UP},  // TODO: first col here is FLIP
  { SGUI(KC_RBRACKET),          KC_SPACE,         KC_RGUI,       KC_RALT,  KC_RCTRL,     KC_LEFT,     KC_DOWN, KC_RIGHT},
},
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |-------|    |-------|   +  |   -  |   =  |   [  |   ]  |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = {
    // LEFT HAND
    {   RESET,   KC_F1,      KC_F2,            KC_F3,       KC_F4,   KC_F5,             KC_F6, _______},
    { _______, _______,    _______,         KC_MS_UP,     _______, _______,           _______, _______},
    { _______, _______, KC_MS_LEFT,       KC_MS_DOWN, KC_MS_RIGHT, RGB_HUI,           _______, _______},
    { _______, _______,    RGB_TOG, RGB_MODE_FORWARD,     RGB_HUI, RGB_SAI,           RGB_VAI, _______},
    { _______, _______, KC_MS_BTN2,          _______,  KC_MS_BTN1, _______, SGUI(KC_RBRACKET), _______},
    { _______, _______,    _______,          _______,     _______, _______,           _______, _______},

    // RIGHT HAND
    { _______, KC_MEDIA_PREV_TRACK, KC_MEDIA_PLAY_PAUSE, KC_MEDIA_NEXT_TRACK, _______, _______,   _______, _______},
    {   KC_F7,               KC_F8,               KC_F9,              KC_F10,  KC_F11,  KC_F12, KC_DELETE, _______},
    { _______,             _______,               KC_UP,             _______, _______, _______,   _______, _______},
    { KC_LEFT,             KC_DOWN,               KC_UP,            KC_RIGHT, _______, _______,   _______, _______},
    { _______,             _______,             _______,             _______, _______, _______,   _______, _______},
    { _______,             _______,             _______,             _______, _______, _______,   _______, _______},
},

#if 0
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
#endif
};

// int RGB_current_mode;

void matrix_init_user(void) {
  /*
    #ifdef RGBLIGHT_ENABLE
        RGB_current_mode = rgblight_config.mode;
        rgblight_enable(); // Ian: switch on RGB
    #endif
    // */
    //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
    #ifdef SSD1306OLED
        oled_init(!has_usb());   // turns on the display
    #endif
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

void oled_task_user(void) {
  if (is_master) {
    oled_write_ln(read_layer_state(), 0);
  } else {
    oled_write(read_logo(), 0);
  }
}
#endif//SSD1306OLED


/*
// not working
const rgblight_segment_t PROGMEM my_raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_RED}       // Light everything red
);

const rgblight_segment_t PROGMEM my_game_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, RGBLED_NUM, HSV_GREEN}
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_raise_layer,
    my_game_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
*/
