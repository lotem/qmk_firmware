#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3
#define _MAC 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  MAC,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * | Esc|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
     * |-----------------------------------------------------------|
     * | Tab |  A |  S |  D |  F |  G |  H |  J |  K |  L |  ;     |
     * |-----------------------------------------------------------|
     * |  \ fn  |  Z |  X |  C |  V |  B |  N |  M |  ,  |  . |fn/ |
     * |-----------------------------------------------------------|
     * | LCtl | LGui| LAlt|   LSht    |     spc     |fn2|RAlt|RCtl |
     * `-----------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_ESC,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,   KC_BSPC,\
        LT(_RAISE, KC_TAB), KC_A, KC_S,  KC_D,   KC_F,   KC_G,   KC_H,   KC_J,    KC_K,    KC_L,   LT(_RAISE, KC_SCLN), \
        LT(_LOWER, KC_BSLS), KC_Z, KC_X, KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT, LT(_LOWER, KC_SLSH), \
        KC_LCTL, KC_LGUI, KC_LALT, KC_LSFT, KC_SPC, LT(_ADJUST, KC_LGUI), KC_RALT, KC_RCTL \
        ),

    /* Lower Layer
     * ,-----------------------------------------------------------.
     * |  ` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |Del |
     * |-----------------------------------------------------------|
     * |     |  - |  = |  ( |  ) |  ; |Left| Dn | Up |Rght|  '     |
     * |-----------------------------------------------------------|
     * |        |  ` |  ' |  [ |  ] |  \ |  - |  = |     |    |    |
     * |-----------------------------------------------------------|
     * |      |     |     |           |    Enter    |   |    |     |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
        _______, KC_MINS, KC_EQL,  KC_LPRN, KC_RPRN, KC_SCLN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_QUOT, \
        _______, KC_GRV,  KC_QUOT, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,  _______, _______, _______, \
        _______, _______, _______, _______, KC_ENT,  _______, _______, _______ \
        ),

    /* Raise Layer
     * ,-----------------------------------------------------------.
     * |  ~ |  ! |  @ |  # |  $ |  % |  ^ |  & |  * |  ( |  ) |Del |
     * |-----------------------------------------------------------|
     * |     |  _ |  + |  ( |  ) |  : |Home|PgDn|PgUp|End |   "    |
     * |-----------------------------------------------------------|
     * |        |  ~ |  " |  { |  } |Pipe|  _ |  + | MS2 |MSU |MS3 |
     * |-----------------------------------------------------------|
     * |      |     |     |           |    MS Btn 1 |MSL| MSD| MSR |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = LAYOUT( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
        _______, KC_UNDS, KC_PLUS, KC_LPRN, KC_RPRN, KC_COLN, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  KC_DQT, \
        _______, KC_TILD, KC_DQT,  KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS, KC_PLUS, KC_MS_BTN2, KC_MS_UP, KC_MS_BTN3, \
        _______, _______, _______, _______, KC_MS_BTN1, KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT \
        ),

    /* Adjust Layer
     * ,-----------------------------------------------------------.
     * |RSET| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10| Del|
     * |-----------------------------------------------------------|
     * |Caps | F11| F12| AU+| AU-| AG=|AGSW| BL*| BL+| BL-|        |
     * |-----------------------------------------------------------|
     * |        | NK+| NK-|RGB*|    |    |    |    |     |    |    |
     * |-----------------------------------------------------------|
     * |SYSSLP|     | Mac*|           |             |   |    |     |
     * `-----------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT( \
        RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_DEL, \
        KC_CAPS, KC_F11,  KC_F12,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, BL_TOGG, BL_INC,  BL_DEC,  _______, \
        _______, NK_ON,   NK_OFF,  RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, \
        KC_SYSTEM_SLEEP, _______, TG(_MAC), _______, _______, _______, _______, _______ \
        ),

    /* Mac Layer
     * ,-----------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |
     * |-----------------------------------------------------------|
     * |     |    |    |    |    |    |    |    |    |    |        |
     * |-----------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |     |    |    |
     * |-----------------------------------------------------------|
     * |      | LAlt| LGui|           |             |   |    |     |
     * `-----------------------------------------------------------'
     */
    [_MAC] = LAYOUT( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______ \
        ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch (keycode) {

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
    case MAC:
      if (record->event.pressed) {
        layer_on(_MAC);
      } else {
        layer_off(_MAC);
      }
      return false;
      break;
  }
  return true;
}
