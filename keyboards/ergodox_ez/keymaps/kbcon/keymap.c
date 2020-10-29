#include QMK_KEYBOARD_H
#include "version.h"

#define BASE 0 // default layer
#define HOMELY 1 // homely layer
#define STENO 2 // stenotype
#define SYMB 3 // symbols
#define MDIA 7 // media keys


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
 * |   [    |   1  |   2  |   3  |   4  |   5  | STENO|           | NumLk|   6  |   7  |   8  |   9  |   0  |   ]    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   =    |   Q  |   W  |   E  |   R  |   T  |   `  |           | Del  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   -    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  Tab |           | BkSp |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | MDIA | Ctrl |  Alt |  Gui | SYMB |                                       | SYMB | Left | Down |  Up  | Right|
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | MDIA | Ctrl |       | Ctrl | MDIA |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      | Alt  | Alt  |       | Alt  |      |      |
 *                                 | Ctrl | Esc  |------|       |------| Enter| Space|
 *                                 |      |      | Gui  |       | Gui  |      |      |
 *                                 `--------------------'       `--------------------'
 */
[BASE] = LAYOUT_ergodox(
  // left hand
  KC_LBRC,      KC_1,    KC_2,     KC_3,     KC_4,    KC_5,     TG(STENO),
  KC_EQL,       KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,     KC_GRV,
  KC_MINS,      KC_A,    KC_S,     KC_D,     KC_F,    KC_G,
  KC_LSFT,      KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,     KC_TAB,
  MO(MDIA),     KC_LCTL, KC_LALT,  KC_LGUI,  MO(SYMB),
                                                      MO(MDIA), KC_LCTL,
                                                                KC_LALT,
                                        KC_LCTL, ALT_T(KC_ESC), KC_LGUI,
  // right hand
  TG(MDIA),     KC_6,    KC_7,     KC_8,     KC_9,    KC_0,     KC_RBRC,
  KC_DEL,       KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_BSLS,
                KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
  KC_BSPC,      KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
                         MO(SYMB), KC_LEFT,  KC_DOWN, KC_UP,    KC_RGHT,
  KC_RCTL, MO(MDIA),
  KC_RALT,
  KC_RGUI, KC_ENT, KC_SPC
),
/* Keymap 1: Norman layout
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   Q  |   W  |   D  |   F  |   K  |      |           |      |   J  |   U  |   R  |   L  |   ;  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   A  |   S  |   E  |   T  |   G  |------|           |------|   Y  |   N  |   I  |   O  |   H  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   Z  |   X  |   C  |   V  |   B  |      |           |      |   P  |   M  |   ,  |   .  |   /  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[HOMELY] = LAYOUT_ergodox(
  // left hand
  KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
  KC_TRNS,      KC_Q,    KC_W,     KC_D,     KC_F,    KC_K,     KC_TRNS,
  KC_TRNS,      KC_A,    KC_S,     KC_E,     KC_T,    KC_G,
  KC_TRNS,      KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,     KC_TRNS,
  KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS,
                                                      KC_TRNS,  KC_TRNS,
                                                                KC_TRNS,
                                              KC_TRNS, KC_TRNS, KC_TRNS,
  // right hand
  KC_TRNS,      KC_TRNS, KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,
  KC_TRNS,      KC_J,    KC_U,     KC_R,     KC_L,    KC_SCLN,  KC_TRNS,
                KC_Y,    KC_N,     KC_I,     KC_O,    KC_H,     KC_TRNS,
  KC_TRNS,      KC_P,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_TRNS,
                         KC_TRNS,  KC_TRNS,  KC_TRNS, KC_TRNS,  KC_TRNS,

  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Stenotype
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | BKSPC  |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
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
    // left hand
       KC_BSPC, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
       KC_NO,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,
       KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,
       KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_NO,
                                                    KC_NO,
                                  KC_C,    KC_V,    KC_NO,
    // right hand
       KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
       KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
       KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_NO,   KC_TRNS,
       KC_NO,
       KC_NO,   KC_N,    KC_M
),
/* Keymap 3: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |   F11   |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |  F12   |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   `  |   &  |   *  |   '  |   "  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  CAPS   |   #  |   $  |   (  |   )  |  Tab |------|           |------| BkSp |   -  |   +  |   =  |   :  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   \  |      |           |      |   ~  |   _  |   <  |   >  |   ?  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      | Home | PgDn | PgUp | End  |
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
           KC_BSPC, KC_MINS, KC_PLUS, KC_EQL,  KC_COLN, KC_TRNS,
  KC_TRNS, KC_TILD, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, KC_TRNS,
                    KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
  KC_TRNS, KC_TRNS,
  KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 7: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |SYSSLEEP|HOMELY|      |      |      |      |      |           |      |      |      |      |      |QWERTY| RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      |      |           |      |      |   7  |   8  |   9  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        | App  |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      | WBak |      |           |      |      |   1  |   2  |   3  |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       | Play | Prev | VolDn| VolUp| Next |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Mclk |      |       |      | Mute |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk | Rclk |------|       |------|   .  |   0  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox(
  // left hand
  KC_SLEP, DF(HOMELY), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_WH_U, KC_TRNS,
  KC_TRNS, KC_APP,  KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_WBAK, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                               KC_BTN3, KC_TRNS,
                                                        KC_TRNS,
                                      KC_BTN1, KC_BTN2, KC_TRNS,
  // right hand
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, DF(BASE), RESET,
  KC_TRNS, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_TRNS, KC_TRNS,
           KC_TRNS, KC_4,    KC_5,    KC_6,    KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_TRNS, KC_TRNS,
                    KC_MPLY, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
  KC_TRNS, KC_MUTE,
  KC_TRNS,
  KC_TRNS, KC_DOT,  KC_0
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
