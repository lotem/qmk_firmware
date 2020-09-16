#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _HOMELY 1
#define _COMBO 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  HOMELY,
  COMBO,
  LOWER,
  RAISE,
  ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
     * |-----------------------------------------------------------|
     * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L |  Ent   |
     * |-----------------------------------------------------------|
     * | LSft   | ^Z |  X |  C |  V |  B |  N |  M |  ,  |  . | ^/ |
     * |-----------------------------------------------------------|
     * | LGui | LAlt| LCtl|  Lower ;  |     spc     |Ctl|RAlt|RGui*|
     * `-----------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC, \
        KC_TAB,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_ENT, \
        KC_LSFT, LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_N, KC_M,   KC_COMM, RSFT_T(KC_DOT), LT(_RAISE, KC_SLSH), \
        KC_LGUI, KC_LALT, KC_LCTL, LT(_LOWER, KC_SCLN), KC_SPC, KC_RCTL, KC_RALT, LT(_ADJUST, KC_RGUI) \
        ),

    /* Homely Layer
     * ,-----------------------------------------------------------.
     * | Esc|  Q |  W |  D |  F |  K |  J |  U |  R |  L |  ; | BS |
     * |-----------------------------------------------------------|
     * | Tab |  A |  S |  E |  T |  G |  Y |  N |  I |  O |  H     |
     * |-----------------------------------------------------------|
     * | LSft   | ^Z |  X |  C |  V |  B |  P |  M |  ,  |  . | ^/ |
     * |-----------------------------------------------------------|
     * | LGui | LAlt| LCtl| Lower/Ent |     spc     |Ctl|RAlt|RGui*|
     * `-----------------------------------------------------------'
     */
    [_HOMELY] = LAYOUT( \
        KC_ESC,  KC_Q,    KC_W,    KC_D,    KC_F,   KC_K,   KC_J,   KC_U,   KC_R,   KC_L,   KC_SCLN, KC_BSPC,\
        KC_TAB,  KC_A,    KC_S,    KC_E,    KC_T,   KC_G,   KC_Y,   KC_N,   KC_I,   KC_O,   KC_H, \
        KC_LSFT, LT(_RAISE, KC_Z), KC_X, KC_C, KC_V, KC_B, KC_P, KC_M, KC_COMM, KC_DOT, LT(_RAISE, KC_SLSH), \
        KC_LGUI, KC_LALT, KC_LCTL, LT(_LOWER, KC_ENT), KC_SPC, KC_RCTL, KC_RALT, LT(_ADJUST, KC_RGUI) \
        ),

    /* Combo Layer: I have more fingers than you!
     * ,-----------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |
     * |-----------------------------------------------------------|
     * |     |    |    |    |    |    |    |    |    |    |        |
     * |-----------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |     |    |    |
     * |-----------------------------------------------------------|
     * |      |     |Lower|    Ctrl   |     spc     |Lwr|    |     |
     * `-----------------------------------------------------------'
     */
    [_COMBO] = LAYOUT( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, MO(_LOWER), KC_LCTL, KC_SPC, MO(_LOWER), _______, _______ \
        ),

    /* Lower Layer
     * ,-----------------------------------------------------------.
     * |  ` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |Del |
     * |-----------------------------------------------------------|
     * |Caps |  \ |  ' |  ( |  ) |  ; |Left| Dn | Up |Rght|  '     |
     * |-----------------------------------------------------------|
     * |        |  - |  = |  [ |  ] |  \ |  - |  = |     |    |    |
     * |-----------------------------------------------------------|
     * |      |     |     |           |     Ent     |   |    |     |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
        KC_CAPS, KC_BSLS, KC_QUOT, KC_LPRN, KC_RPRN, KC_SCLN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, \
        _______, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, _______, \
        _______, _______, _______, _______, KC_ENT,  _______, _______, _______ \
        ),

    /* Raise Layer
     * ,-----------------------------------------------------------.
     * |  ~ |  ! |  @ |  # |  $ |  % |  ^ |  & |  * |  ( |  ) |Del |
     * |-----------------------------------------------------------|
     * |Caps |Pipe|  " |  ( |  ) |  : |Home|PgDn|PgUp|End |  "     |
     * |-----------------------------------------------------------|
     * |        |  _ |  + |  { |  } |Pipe|  _ |  + | MS2 |MSU |MS3 |
     * |-----------------------------------------------------------|
     * |      |     |     |           |    MS Btn 1 |MSL| MSD| MSR |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = LAYOUT( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
        KC_CAPS, KC_PIPE, KC_DQT,  KC_LPRN, KC_RPRN, KC_COLN, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQT, \
        _______, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS, KC_PLUS, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN3, \
        _______, _______, _______, _______, KC_MS_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT \
        ),

    /* Adjust Layer
     * ,-----------------------------------------------------------.
     * |SLEP| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| Del|
     * |-----------------------------------------------------------|
     * |Caps | F11| F12| AU+| AU-| AG=|AGSW| BL*| BL+| BL-| Homely*|
     * |-----------------------------------------------------------|
     * |        | NK+| NK-|RGB*|    |    |    |    |     |    |    |
     * |-----------------------------------------------------------|
     * |      |     |     |   Combo*  |             |   |    |     |
     * `-----------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT( \
        KC_SLEP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
        KC_CAPS, KC_F11,  KC_F12,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, BL_TOGG, BL_INC,  BL_DEC,  TG(_HOMELY), \
        _______, NK_ON,   NK_OFF,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, \
        _______, _______, _______, TG(_COMBO), _______, _______, _______, _______ \
        ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {
    case HOMELY:
      if (record->event.pressed) {
        layer_on(_HOMELY);
      } else {
        layer_off(_HOMELY);
      }
      return false;
      break;
    case COMBO:
      if (record->event.pressed) {
        layer_on(_COMBO);
      } else {
        layer_off(_COMBO);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
