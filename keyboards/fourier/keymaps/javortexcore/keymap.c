#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1
#define _FN2 2
#define _FN3 3

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_FN1 MO(_FN1)
#define KC_FN2 MO(_FN2)
#define KC_FN3 MO(_FN3)
#define KC_SPFN1 LT(_FN1, KC_SPACE)
#define KC_BSFN2 LT(_FN2, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,          KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT, KC_FN1,
    KC_LCTL, KC_LGUI, KC_LALT, KC_FN2,  KC_SPACE,         KC_SPACE,                  KC_RCTL, KC_RALT, KC_FN3, KC_FN2
  ),

  [_FN1] = LAYOUT(
    KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,          KC_EQL,
    _______, _______, _______, _______, _______, KC_QUOT,          KC_SLSH, KC_LBRC, KC_RBRC, KC_BSLS, _______, _______,
    _______, _______, _______, _______, _______,          _______,                   _______, _______, _______, _______
  ),

  [_FN2] = LAYOUT(
    KC_TILD, KC__VOLDOWN, KC__VOLUP, KC__MUTE, _______, _______, _______, KC_PGUP, KC_UP, KC_PGDN, KC_RPRN, KC_SLCK, KC_PAUS,
    KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,         KC_PLUS,
    _______, _______, _______, _______,  _______, KC_DQUO, KC_QUES,      KC_LCBR, KC_RCBR, KC_PIPE, _______, _______,
    _______, _______, _______, _______,  _______,           _______,                   _______, _______, _______, _______
  ),
  
  [_FN3] = LAYOUT(
    _______, KC__VOLDOWN, KC__VOLUP, KC__MUTE, _______, _______, _______, KC_PGUP, KC_UP, KC_PGDN, KC_RPRN, KC_SLCK, KC_PAUS,
    KC_CLCK, KC_MRWD, KC_MPLY, KC_MFFD, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_INS,         KC_PLUS,
    _______, _______, _______, _______,  _______, _______, KC_END,      TG(_BASE), TG(_FN1), TG(_FN2), TG(_FN3), _______,
    _______, _______, _______, _______,  _______,           _______,                   _______, _______, _______, _______
  )

};
