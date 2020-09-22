#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define STENO 1 // stenotype
#define SYMB 2 // symbols
#define MDIA 3 // media keys


enum custom_keycodes {
#ifdef ORYX_CONFIGURATOR
  EPRM = EZ_SAFE_RANGE,
#else
  EPRM = SAFE_RANGE,
#endif
  VRSN,
  RGB_SLD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   `  |           |  LSw |   6  |   7  |   8  |   9  |   0  |  Del   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   [  |           |   ]  |   Y  |   U  |   I  |   O  |   P  |  BkSp  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   \    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|   -  |           |   =  |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |  Alt |           |  Alt |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | MDIA | Ctrl |  Alt |  Gui | SYMB |                                       | SYMB |  Gui |  Alt | Ctrl | MDIA |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Right|       | Esc  | Tab  |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | BkSp |  Up  |       | PgUp |      |      |
 *                                 | Ctrl | Shift|------|       |------| Enter| Space|
 *                                 |      |      | Down |       | PgDn |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_ESC,          KC_1,    KC_2,     KC_3,     KC_4,    KC_5,    KC_GRV,
  KC_TAB,          KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,    KC_LBRC,
  KC_BSLS,         KC_A,    KC_S,     KC_D,     KC_F,    KC_G,
  KC_LSFT,         KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,    ALT_T(KC_MINS),
  MO(MDIA),        KC_LCTL, KC_LALT,  KC_LGUI,  MO(SYMB),
                                                         KC_LEFT, KC_RGHT,
                                                                  KC_UP,
                                         KC_LCTL, SFT_T(KC_BSPC), KC_DOWN,
  // right hand
  TG(STENO),       KC_6,    KC_7,     KC_8,     KC_9,    KC_0,    KC_DEL,
  KC_RBRC,         KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,    KC_BSPC,
                   KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN, KC_QUOT,
  ALT_T(KC_EQL),   KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH, KC_RSFT,
                            MO(SYMB), KC_RGUI,  KC_RALT, KC_RCTL, MO(MDIA),
  GUI_T(KC_ESC), KC_TAB,
  ALT_T(KC_PGUP),
  CTL_T(KC_PGDN), KC_ENT, KC_SPC
),
/* Keymap 5: Stenotype
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |  LSw |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   #  |   #  |   #  |   #  |   #  |      |           |      |   #  |   #  |   #  |   #  |   #  |   #    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   T  |   P  |   H  |   *  |------|           |------|   *  |   F  |   P  |   L  |   T  |   D    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   S  |   K  |   W  |   R  |   *  |      |           |      |   *  |   R  |   B  |   G  |   S  |   Z    |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |   A  |   O  |------|       |------|   E  |   U  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[STENO] = LAYOUT_ergodox(
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_NO,
       KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_NO,
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                                           KC_NO,   KC_NO,
                                                    KC_NO,
                                  KC_C,    KC_V,    KC_NO,
    // right hand
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_NO,   KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
       KC_NO,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                         KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_NO,
       KC_NO,
       KC_NO,   KC_N,    KC_M
),
/* Keymap 6: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   F11   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   `  |   &  |   *  |   '  |   "  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS   |   #  |   $  |   (  |   )  |  Tab |------|           |------| Left | Down |  Up  | Right| BkSp |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   \  |      |           |      |   ~  |   _  |   -  |   =  |   +  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |      |      |      |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox(
  // left hand
  KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,
  KC_CAPS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_TAB,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_BSLS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
  KC_TRNS, KC_GRV,  KC_AMPR, KC_ASTR, KC_QUOT, KC_DQT,  KC_TRNS,
           KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_BSPC, KC_TRNS,
  KC_TRNS, KC_TILD, KC_UNDS, KC_MINS, KC_EQL,  KC_PLUS, KC_TRNS,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 7: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |Version |      |      |      |      |      |      |           |      |      |      |      |      |      |  EPRM  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |  Prev  |      |      | MsUp |      |      |      |           |      |      |   7  |   8  |   9  |      |  VolUp |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Play  |      |MsLeft|MsDown|MsRght|      |------|           |------| Home |   4  |   5  |   6  |      |  Mute  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  Next  |      |      |      |      |      |      |           |      | End  |   1  |   2  |   3  |      |  VolDn |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       | App  |      |      |
 *                                 |      |      |------|       |------|   .  |   0  |
 *                                 |      |      |      |       |BrwsBk|      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  VRSN,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_MPRV, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_MPLY, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
  KC_MNXT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,
                                               KC_TRNS, KC_TRNS,
                                                        KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, EPRM,
  KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_VOLU,
           KC_HOME, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_MUTE,
  KC_TRNS, KC_END,  KC_1,    KC_2,    KC_3,    KC_TRNS, KC_VOLD,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS,
  KC_APP,
  KC_WBAK, KC_DOT,  KC_0
),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case EPRM:
        eeconfig_init();
        return false;
      case VRSN:
        SEND_STRING (QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
        return false;
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #else
        #ifdef RGBLIGHT_ENABLE
          rgblight_init();
        #endif
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};
