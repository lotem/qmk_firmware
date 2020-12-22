#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _TYPEWR 1
#define _LOWER 2
#define _RAISE 3
#define _ADJUST 4

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TYPEWR,
  LOWER,
  RAISE,
  ADJUST,
};

#define RAI_ESC LT(_RAISE, KC_ESC)
#define SFT_SLSH RSFT_T(KC_SLSH)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Default Layer
     * ,-----------------------------------------------------------.
     * | Tab|  Q |  W |  E |  R |  T |  Y |  U |  I |  O |  P | BS |
     * |-----------------------------------------------------------|
     * | Esc^|  A |  S |  D |  F |  G |  H |  J |  K |  L |  Enter |
     * |-----------------------------------------------------------|
     * | LSft   |  Z |  X |  C |  V |  B |  N |  M |  ,  |  . | S/ |
     * |-----------------------------------------------------------|
     * | Lower| Gui | Alt |    Ctrl   |     spc     |Alt| fn |Rais |
     * `-----------------------------------------------------------'
     */
    [_QWERTY] = LAYOUT( \
        KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC, \
        RAI_ESC, KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_ENT, \
        KC_LSFT, KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  SFT_SLSH, \
        MO(_LOWER), KC_LGUI, KC_LALT, KC_LCTL, KC_SPC, KC_RALT, MO(_ADJUST), MO(_RAISE) \
        ),

    /* Typewriter Layer
     * ,-----------------------------------------------------------.
     * |    |    |    |    |    |    |    |    |    |    |    |    |
     * |-----------------------------------------------------------|
     * | Esc |    |    |    |    |    |    |    |    |    |        |
     * |-----------------------------------------------------------|
     * |        |    |    |    |    |    |    |    |     |    |    |
     * |-----------------------------------------------------------|
     * | Ctrl | Gui | Alt | Lower/spc |  Raise/spc  |Alt| fn |Ctrl |
     * `-----------------------------------------------------------'
     */
    [_TYPEWR] = LAYOUT( \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_ESC,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
        KC_LCTL, KC_LGUI, KC_LALT, LT(_LOWER, KC_SPC), LT(_RAISE, KC_SPC), KC_RALT, MO(_ADJUST), KC_RCTL \
        ),

    /* Lower Layer
     * ,-----------------------------------------------------------.
     * |  ~ |  ! |  @ |  # |  $ |  % |  ^ |  & |  * |  ( |  ) |Del |
     * |-----------------------------------------------------------|
     * | Caps|  ~ |  " |  ( |  ) |  : |Left| Dn | Up |Rght|        |
     * |-----------------------------------------------------------|
     * |        |  ? |Pipe|  { |  } |Pipe|  _ |  + | MS1 |MSU |MS2 |
     * |-----------------------------------------------------------|
     * |      |     |     |           |     Ins     |MSL| MSD| MSR |
     * `-----------------------------------------------------------'
     */
    [_LOWER] = LAYOUT( \
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, \
        KC_CAPS, KC_TILD, KC_DQT,  KC_LPRN, KC_RPRN, KC_COLN, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, \
        _______, KC_QUES, KC_PIPE, KC_LCBR, KC_RCBR, KC_PIPE, KC_UNDS, KC_PLUS, KC_MS_BTN1, KC_MS_UP, KC_MS_BTN2, \
        _______, _______, _______, _______, KC_INS,  KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT \
        ),

    /* Raise Layer
     * ,-----------------------------------------------------------.
     * |  ` |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  8 |  9 |  0 |Del |
     * |-----------------------------------------------------------|
     * | Caps|  ` |  ' |  ( |  ) |  ; |Home|PgDn|PgUp|End |        |
     * |-----------------------------------------------------------|
     * |        |  / |  \ |  [ |  ] |  \ |  - |  = |  <  |  > |    |
     * |-----------------------------------------------------------|
     * |      |     |     |           |     Ins     |   |    |     |
     * `-----------------------------------------------------------'
     */
    [_RAISE] = LAYOUT( \
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL, \
        KC_CAPS, KC_GRV,  KC_QUOT, KC_LPRN, KC_RPRN, KC_SCLN, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, \
        _______, KC_SLSH, KC_BSLS, KC_LBRC, KC_RBRC, KC_BSLS, KC_MINS, KC_EQL,  KC_LABK, KC_RABK, _______, \
        _______, _______, _______, _______, KC_INS,  _______, _______, _______ \
        ),

    /* Adjust Layer
     * ,-----------------------------------------------------------.
     * | SLP| F1 | F2 | F3 | F4 | F5 | F6 | F7 | F8 | F9 | F10|RST |
     * |-----------------------------------------------------------|
     * | Caps| F11| F12|Prev|Play|Next|Mute|Vol-|Vol+|    |        |
     * |-----------------------------------------------------------|
     * |        | BR-| BR+| NK-| NK+|    |WBak|WFwd| WhDn|WhUp|    |
     * |-----------------------------------------------------------|
     * |      |     |     |     L0    |     L1      |AGT|    |     |
     * `-----------------------------------------------------------'
     */
    [_ADJUST] = LAYOUT( \
        KC_SLEP, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  RESET, \
        KC_CAPS, KC_F11,  KC_F12,  KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, \
        _______, KC_BRID, KC_BRIU, NK_OFF,  NK_ON,   _______, KC_WBAK, KC_WFWD, KC_WH_D, KC_WH_U, _______, \
        _______, _______, _______, DF(_QWERTY), DF(_TYPEWR), AG_TOGG, _______, _______ \
        ),

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case TYPEWR:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_TYPEWR);
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
