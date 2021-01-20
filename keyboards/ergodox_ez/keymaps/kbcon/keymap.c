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
  PLON,
  PLOFF,
};

#ifdef STENO_ENABLE
#include "keymap_steno.h"
#define STN_ON TG(STENO)
#define STN_OFF TG(STENO)
#else
#define STN_ON PLON
#define STN_OFF PLOFF
#define STN_N1 KC_1
#define STN_N2 KC_2
#define STN_N3 KC_3
#define STN_N4 KC_4
#define STN_N5 KC_5
#define STN_N6 KC_6
#define STN_N7 KC_7
#define STN_N8 KC_8
#define STN_N9 KC_9
#define STN_NA KC_0
#define STN_NB KC_MINS
#define STN_NC KC_EQL
#define STN_S1 KC_Q
#define STN_S2 KC_A
#define STN_TL KC_W
#define STN_KL KC_S
#define STN_PL KC_E
#define STN_WL KC_D
#define STN_HL KC_R
#define STN_RL KC_F
#define STN_ST1 KC_T
#define STN_ST2 KC_G
#define STN_ST3 KC_Y
#define STN_ST4 KC_H
#define STN_FR KC_U
#define STN_RR KC_J
#define STN_PR KC_I
#define STN_BR KC_K
#define STN_LR KC_O
#define STN_GR KC_L
#define STN_TR KC_P
#define STN_SR KC_SCLN
#define STN_DR KC_LBRC
#define STN_ZR KC_QUOT
#define STN_A KC_C
#define STN_O KC_V
#define STN_E KC_N
#define STN_U KC_M
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   [    |   1  |   2  |   3  |   4  |   5  | STN+ |           | NumLk|   6  |   7  |   8  |   9  |   0  |   ]    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   =    |   Q  |   W  |   E  |   R  |   T  |   `  |           | Del  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |   -    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  Tab |           | BkSp |------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | Ctrl |  Alt |  Del |  Ins | SYMB |                                       | SYMB | Left | Down |  Up  | Right|
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
    KC_LBRC,      KC_1,    KC_2,     KC_3,     KC_4,    KC_5,     STN_ON,
    KC_EQL,       KC_Q,    KC_W,     KC_E,     KC_R,    KC_T,     KC_GRV,
    KC_MINS,      KC_A,    KC_S,     KC_D,     KC_F,    KC_G,
    KC_LSFT,      KC_Z,    KC_X,     KC_C,     KC_V,    KC_B,     KC_TAB,
    KC_LCTL,      KC_LALT, KC_DEL,   KC_INS,   MO(SYMB),
    /**/                                                MO(MDIA), KC_LCTL,
    /**/                                                          KC_LALT,
    /**/                                  KC_LCTL, ALT_T(KC_ESC), KC_LGUI,
    // right hand
    TG(MDIA),     KC_6,    KC_7,     KC_8,     KC_9,    KC_0,     KC_RBRC,
    KC_DEL,       KC_Y,    KC_U,     KC_I,     KC_O,    KC_P,     KC_BSLS,
    /**/          KC_H,    KC_J,     KC_K,     KC_L,    KC_SCLN,  KC_QUOT,
    KC_BSPC,      KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
    /**/                   MO(SYMB), KC_LEFT,  KC_DOWN, KC_UP,    KC_RGHT,
    KC_RCTL, MO(MDIA),
    KC_RALT,
    KC_RGUI, KC_ENT, KC_SPC
),
/* Keymap 1: Stenotype
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      | STN- |           |      |      |      |      |      |      |        |
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
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   STN_OFF,
    KC_NO,   STN_N1,  STN_N2,  STN_N3,  STN_N4,  STN_N5,  KC_NO,
    KC_NO,   STN_S1,  STN_TL,  STN_PL,  STN_HL,  STN_ST1,
    KC_NO,   STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_ST2, KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /**/                                         KC_TRNS, KC_NO,
    /**/                                                  KC_NO,
    /**/                                STN_A,   STN_O,   KC_NO,
    // right hand
    KC_TRNS, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
    KC_NO,   STN_N6,  STN_N7,  STN_N8,  STN_N9,  STN_NA,  STN_NB,
    /**/     STN_ST3, STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
    KC_NO,   STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
    /**/              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_NO,   KC_TRNS,
    KC_NO,
    KC_NO,   STN_E,   STN_U
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
    /**/                                         KC_TRNS, KC_TRNS,
    /**/                                                  KC_TRNS,
    /**/                                KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
    KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F12,
    KC_TRNS, KC_GRV,  KC_AMPR, KC_ASTR, KC_QUOT, KC_DQT,  KC_TRNS,
    /**/     KC_BSPC, KC_MINS, KC_PLUS, KC_EQL,  KC_COLN, KC_TRNS,
    KC_TRNS, KC_TILD, KC_UNDS, KC_LABK, KC_RABK, KC_QUES, KC_TRNS,
    /**/              KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_TRNS, KC_TRNS,
    KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 7: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |SYSSLEEP|      |      |      |      |      |      |           |      |      |      |      |      |      | RESET  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      | MsUp |      |      | MwUp |           | VolUp|      |   7  |   8  |   9  | Prev |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |MsLeft|MsDown|MsRght|      |------|           |------|      |   4  |   5  |   6  | Play |        |
 * |--------+------+------+------+------+------| MwDn |           | VolDn|------+------+------+------+------+--------|
 * |        | Undo | App  | WBak | WFwd |      |      |           |      |      |   1  |   2  |   3  | Next |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
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
    KC_SLEP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, KC_WH_U,
    KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_R, KC_TRNS,
    KC_TRNS, KC_UNDO, KC_APP,  KC_WBAK, KC_WFWD, KC_TRNS, KC_WH_D,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    /**/                                         KC_BTN3, KC_TRNS,
    /**/                                                  KC_TRNS,
    /**/                                KC_BTN1, KC_BTN2, KC_TRNS,
    // right hand
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, RESET,
    KC_VOLU, KC_TRNS, KC_7,    KC_8,    KC_9,    KC_MPRV, KC_TRNS,
             KC_TRNS, KC_4,    KC_5,    KC_6,    KC_MPLY, KC_TRNS,
    KC_VOLD, KC_TRNS, KC_1,    KC_2,    KC_3,    KC_MNXT, KC_TRNS,
    /**/              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
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
      case PLON:
        if (record->event.pressed) {
          layer_on(STENO);
          // send PHRO*PB - plover on
          SEND_STRING(
              SS_DOWN(X_E) SS_DOWN(X_R) SS_DOWN(X_F) SS_DOWN(X_V)
              SS_DOWN(X_Y) SS_DOWN(X_I) SS_DOWN(X_K)
              SS_UP(X_E) SS_UP(X_R) SS_UP(X_F) SS_UP(X_V)
              SS_UP(X_Y) SS_UP(X_I) SS_UP(X_K));
        }
        return false;
      case PLOFF:
        if (record->event.pressed) {
          layer_off(STENO);
          // send PHRO*F - plover off
          SEND_STRING(
              SS_DOWN(X_E) SS_DOWN(X_R) SS_DOWN(X_F) SS_DOWN(X_V)
              SS_DOWN(X_Y) SS_DOWN(X_U)
              SS_UP(X_E) SS_UP(X_R) SS_UP(X_F) SS_UP(X_V)
              SS_UP(X_Y) SS_UP(X_U));
        }
        return false;
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
#ifdef STENO_ENABLE
  steno_set_mode(STENO_MODE_GEMINI);
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
