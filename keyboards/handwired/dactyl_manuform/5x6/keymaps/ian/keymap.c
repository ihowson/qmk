/* A standard layout for the Dactyl Manuform 5x6 Keyboard */ 

#include QMK_KEYBOARD_H

#define LAYER_QWERTY 0
#define LAYER_RAISE 1
#define LAYER_MOUSE 2
#define LAYER_LOWER 3

enum custom_keycodes {
    REPEAT_COMMAND = SAFE_RANGE,
};

#define RAISE MO(LAYER_RAISE)
#define LOWER MO(LAYER_LOWER)

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case REPEAT_COMMAND:
        if (record->event.pressed) {
            // up-arrow, enter -- repeats last command in shell
            SEND_STRING(SS_TAP(X_UP)"\n");
        } else {
            // when keycode is released
        }
        break;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [LAYER_QWERTY] = LAYOUT_5x6(
     KC_GRAVE,    KC_1,        KC_2,               KC_3,     KC_4,    KC_5,          KC_6,     KC_7,                   KC_8,      KC_9,      KC_0,  KC_EQUAL,
       KC_TAB,    KC_Q,        KC_W,               KC_E,     KC_R,    KC_T,          KC_Y,     KC_U,                   KC_I,      KC_O,      KC_P, KC_BSLASH,
    KC_ESCAPE,    KC_A,        KC_S,               KC_D,     KC_F,    KC_G,          KC_H,     KC_J,                   KC_K,      KC_L, KC_SCOLON,  KC_QUOTE,
    KC_LSHIFT,    KC_Z,        KC_X,               KC_C,     KC_V,    KC_B,          KC_N,     KC_M,               KC_COMMA,    KC_DOT,  KC_SLASH, KC_RSHIFT,
    // KC_LSHIFT,    KC_Z,        KC_X, MT(MOD_LCTL, KC_C),     KC_V,    KC_B,          KC_N,     KC_M, MT(MOD_RCTL, KC_COMMA),    KC_DOT,  KC_SLASH, KC_RSHIFT,
                        KC_LBRACKET,        KC_RBRACKET,                                                                    KC_BSPACE,  KC_MINUS,
                                                      _______,  _______,              _______,  _______,
                                                        RAISE, KC_LCTRL,                KC_RCTRL,  KC_RGUI,  // pos1, pos2
                                                       KC_LGUI, KC_LALT,              KC_ENTER, KC_SPACE  // pos3, pos4
  ),

  [LAYER_RAISE] = LAYOUT_5x6(
        KC_F12,   KC_F1,       KC_F2,   KC_F3,      KC_F4,   KC_F5,                          KC_F6,             KC_F7,       KC_F8,       KC_F9,      KC_F10,    KC_F11,
       _______,    KC_1,        KC_2,    KC_3,       KC_4,    KC_5,                           KC_6,              KC_7,        KC_8,        KC_9,        KC_0,  KC__MUTE,
       _______, _______, DF(LAYER_QWERTY), DF(LAYER_MOUSE), MO(LAYER_LOWER), KC_BRIGHTNESS_UP,               KC_LEFT,           KC_DOWN,       KC_UP,    KC_RIGHT, KC__VOLDOWN, KC__VOLUP,
       _______, _______,     KC_HOME, _______,    KC_END, KC_BRIGHTNESS_DOWN,   SGUI(KC_LBRACKET), SGUI(KC_RBRACKET), KC_LBRACKET, KC_RBRACKET,       RESET,   _______,
                             _______, _______,                                                              KC_PGDOWN,     KC_PGUP,
                                                      _______, _______,              _______, _______,
                                                      _______, RGB_MODE_FORWARD,     _______, REPEAT_COMMAND,
                                                      RGB_HUI, RGB_SAI,              RGB_TOG, RGB_VAI
  ),

  [LAYER_LOWER] = LAYOUT_5x6(
     KC_TILD,KC_EXLM, KC_AT ,KC_HASH,KC_DLR ,KC_PERC,                        KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,KC_DEL,
     _______,_______,_______,_______,_______,KC_LBRC,                        KC_RBRC, KC_7 , KC_8 , KC_9 ,_______,KC_PLUS,
     _______,KC_HOME,KC_PGUP,KC_PGDN,KC_END ,KC_LPRN,                        KC_RPRN, KC_4 , KC_5 , KC_6 ,KC_MINS,KC_PIPE,
     _______,_______,_______,_______,_______,_______,                        _______, KC_1 , KC_2 , KC_3 ,KC_EQL ,KC_UNDS,
                                             _______,KC_PSCR,            KC_BSPACE, KC_DOT,
                                             _______,_______,            _______,_______,
                                             _______,_______,            KC_HOME,KC_END,
                                             _______,_______,            _______, KC_0

  ),

  [LAYER_MOUSE] = LAYOUT_5x6(
     _______,     _______,     _______,       _______,       _______,        _______,                        _______,    _______,    _______,  _______,     _______, _______,
     _______,     _______,     _______,       KC_MS_WH_UP,   _______,        _______,                        _______,    _______,    KC_MS_UP, _______,     _______, _______,
     DF(LAYER_QWERTY), DF(LAYER_QWERTY), KC_MS_WH_LEFT, KC_MS_WH_DOWN, KC_MS_WH_RIGHT, _______,                        KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, _______, _______,
     _______,     _______,     KC_MS_ACCEL0,  KC_MS_ACCEL1,  KC_MS_ACCEL2,   _______,                        _______,    _______,    _______,  _______,     _______ ,_______,
                                                 _______,    _______,            _______,    _______,
                                                 _______,    _______,            _______,    _______,
                                                 _______,    KC_MS_BTN3,         KC_MS_BTN3, _______,
                                                 KC_MS_BTN1, KC_MS_BTN2,         KC_MS_BTN2, KC_MS_BTN1

  )
};


// Tap Dance definitions

/*
void dance_9(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
      case 1:
        SEND_STRING("9");
        break;
      case 2:
        SEND_STRING("[");
        break;
      case 3:
        SEND_STRING("{");
        break;
      default:
        SEND_STRING("??");
        break;

      reset_tap_dance(state);
    }
}

void dance_9(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
      case 1:
        SEND_STRING(")");
        break;
      case 2:
        SEND_STRING("]");
        break;
      case 3:
        SEND_STRING("}");
        break;
      default:
        SEND_STRING("??");
        break;

      reset_tap_dance(state);
    }
}
*/

// qk_tap_dance_action_t tap_dance_actions[] = {
//     // Tap once for Escape, twice for Caps Lock
//     // [TD_9] = ACTION_TAP_DANCE_FN(dance_9),
//     // [TD_0] = ACTION_TAP_DANCE_FN(dance_0),
//     [TD_9] = ACTION_TAP_DANCE_DOUBLE(KC_9, KC_LBRACKET),
//     [TD_0] = ACTION_TAP_DANCE_DOUBLE(KC_0, KC_RBRACKET),
// };


// extern volatile bool isLeftHand;

// void keyboard_post_init_user(void) {
//     if (isLeftHand) {
//         rgblight_set_clipping_range(0, 4);
//     } else {
//         rgblight_set_clipping_range(4, 4);
//     }
// }
