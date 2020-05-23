#include QMK_KEYBOARD_H
#include "version.h"

#define MOD_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MOD_CTRL_MASK   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MOD_ALT_MASK    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

enum rcj_layers {
  _QWERTY = 0,
  _MOVEMENT,
  _BRACES,
  _SYMBOLS,
  _ADJUST
};

enum rcj_keycodes {
  QWERTY = SAFE_RANGE,
  SYM_CBR,
  SYM_PRN,
  SYM_BRC
};

#define MOD_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MOD_CTRL_MASK   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MOD_ALT_MASK    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define LEADER LCTL(KC_T)
#define SLCTL_T(kc) MT((MOD_LCTL | MOD_LGUI), kc)
#define SLALT_T(kc) MT((MOD_LCTL | MOD_LALT), kc)
#define KC_CME MT((MOD_LCTL | MOD_LALT), KC_ENT)
#define KC_SCD MT((MOD_LGUI | MOD_LCTL), KC_DEL)
#define KC_ZMV LT(_MOVEMENT, KC_Z)
#define KC_MOV MO(_MOVEMENT)
#define KC_SS MT(MOD_LSFT, KC_SPACE)
#define KC_BRSL LT(_BRACES, KC_SLSH)
#define KC_SYM MO(_SYMBOLS)
#define KC_SBUF LCAG(KC_B)
#define KC_PREF LCAG(KC_U)
#define KC_SWIN LCAG(KC_N)
#define KC_ADJT MO(_ADJUST)
#define KC_DQOT LCAG(KC_Q)
#define KC_DBRK LCAG(KC_R)
#define KC_DBRC LCAG(KC_F)
#define KC_DCRL LCAG(KC_C)
#define KC_ANGL LCAG(KC_M)
#define KC_DBUG DEBUG
#define KC_RST RESET
#define KC_SBRC SYM_BRC
#define KC_SPRN SYM_PRN
#define KC_SCBR SYM_CBR

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define ALCT(kc) (kc | QK_LCTL | QK_LALT)
#define KC_ALCT ALCT(KC_NO)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,---------------------------------------------------------.           ,------------------------------------------------------------.
 * | ESC        |   1  |   2  |   3  |    4    |   5  |      |           |      |   6  |   7   |   8  |   9  |    0    | BSCP         |
 * |------------+------+------+------+---------+-------------|           |------+------+-------+------+------+---------+--------------|
 * | TAB        |   Q  |   W  |   E  |    R    |   T  |      |           |      |   Y  |   U   |   I  |   O  |    P    |              |
 * |------------+------+------+------+---------+------|      |           |      |------+-------+------+------+---------+--------------|
 * | SAE        |   A  |   S  |   D  |    F    |   G  |------|           |------|   H  |   J   |   K  |   L  |   Sym   | LEADER       |
 * |------------+------+------+------+---------+------|      |           |      |------+-------+------+------+---------+--------------|
 * |Sup+Ctrl/DEL|   Z  |   X  |   C  |    V    |   B  |      |           |      |   N  |   M   |   ,  |   .  |BRCS/SLSH| HYPER        |
 * `------------+------+------+------+---------+-------------'           `-------------+-------+------+------+---------+--------------'
 *   | Esc      |      |      | NPAD |   Ctrl  |                                       |  Alt  | GUI  |      | ADJUST  | Esc          |
 *   `-----------------------------------------'                                       `----------------------------------------------'
 *                                       ,------------------.       ,---------------.
 *                                       |          |       |       |      |        |
 *                                ,------|----------|-------|       |------+--------+------.
 *                                |      |          |       |       |      |        |      |
 *                                |  SPC | Esc      |-------|       |------| C-c    | Shift|
 *                                |      |          |       |       |      |        |      |
 *                                `-------------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[_QWERTY] = LAYOUT_ergodox(
        // left hand
        KC_ESC, KC_1,    KC_2,    KC_3,        KC_4,      KC_5,   _______,
        KC_TAB, KC_Q,    KC_W,    KC_E,        KC_R,      KC_T,   _______,
        KC_CME, KC_A,    KC_S,    KC_D,        KC_F,      KC_G,
        KC_SCD, KC_Z,    KC_X,    KC_C,        KC_V,      KC_B,   _______,
        KC_ESC, _______, _______, KC_MOV,      KC_LCTL,
                                                           _______, _______,
                                                                    _______,
                                                   KC_SPC, KC_ESC,  _______,
        // right hand
             _______, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
             _______, KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    _______,
                      KC_H, KC_J,    KC_K,    KC_L,    KC_SYM,  KC_QUOT,
             _______, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_BRSL, KC_HYPR,
                            KC_LALT, KC_LGUI, _______, MO(_ADJUST),          KC_ESC,
             _______, _______,
             _______,
             _______, LCTL(KC_C), KC_LSFT
    ),
[_SYMBOLS] = LAYOUT_ergodox(
       // left hand
       KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, _______,
       KC_PERC, KC_DQOT, KC_BSLS, KC_EQL,  KC_DBRK, KC_TILD, _______,
       KC_ASTR, KC_MINS, KC_UNDS, KC_COLN, KC_DBRC, KC_GT,
       KC_ANGL, KC_PLUS, KC_AT,   KC_DCRL, KC_ENT,  KC_SBUF, _______,
       _______, _______, _______, _______, _______,
                                        _______, _______,
                                                 _______,
                               _______, _______, _______,
       // right hand
       _______, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
       _______, KC_PIPE, KC_PREF, KC_TAB,  KC_BSPC, _______, _______,
                KC_AMPR, KC_SCLN, KC_EXLM, KC_LT,   _______, _______,
       _______, KC_SWIN, KC_HASH, KC_DLR,  KC_CIRC, _______, _______,
                            _______,    _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
[_MOVEMENT] = LAYOUT_ergodox(
       _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       _______, KC_PSCR, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, _______,
       _______, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,
       _______, KC_LCTL, KC_INS,  KC_TAB,  KC_SPC,  _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       _______,  KC_0,    KC_7,    KC_8,    KC_9,    _______, KC_F12,
                 KC_DOT,  KC_4,    KC_5,    KC_6,    _______, _______,
       _______,  KC_COMM, KC_1,    KC_2,    KC_3,    _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Braces
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |         |         |         |         |        |
 * |--------+------+------+------+------+-------------|           |------+------+---------+---------+---------+---------+--------|
 * |        |      |  {}  |  {   |  }   |      |      |           |      | STOP |  VDOWN  |   VUP   |         |         |        |
 * |--------+------+------+------+------+------|      |           |      |------+---------+---------+---------+---------+--------|
 * |        |      |  ()  |  (   |  )   |      |------|           |------| LEFT |  DOWN   |   UP    |  RIGHT  |         |        |
 * |--------+------+------+------+------+------|      |           |      |------+---------+---------+---------+---------+--------|
 * |        |      |  []  |  [   |  ]   |      |      |           |      | PLAY |  PREV   |  NEXT   |         |         |        |
 * `--------+------+------+------+------+-------------'           `-------------+---------+---------+---------+---------+--------'
 *   |      |      |      |      |      |                                       |         |         |         |         |      |
 *   `----------------------------------'                                       `----------------------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[_BRACES] = LAYOUT_ergodox(
       KC_ADJT, _______, _______, _______, _______, _______, _______,
       _______, _______, KC_SBRC, KC_LBRC, KC_RBRC, _______, _______,
       _______, _______, KC_SPRN, KC_LPRN, KC_RPRN, _______,
       _______, _______, KC_SCBR, KC_LCBR, KC_RCBR, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, KC_UP,   KC_TAB,  _______, _______,
                 _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
       _______,  _______, KC_ENT,  _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),

[_ADJUST] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, RESET,   DEBUG,   _______, _______, _______, _______,
       _______, QWERTY,  _______, AU_ON,   AU_OFF,  AG_NORM,
       DEBUG,   MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _______,
       RESET,   _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, _______, _______, _______, _______, _______,
                 AG_SWAP, _______, _______, _______, _______, _______,
       _______,  MI_OFF,  _______, _______, _______, _______, _______,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
};


// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

}

layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        break;
      case 1:
        ergodox_right_led_1_on();
        break;
      case 2:
        ergodox_right_led_2_on();
        break;
      case 3:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        break;
      case 4:
        ergodox_right_led_3_on();
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        break;
      default:
        break;
    }

  return state;
};

bool shifted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case SYM_CBR:
        case SYM_PRN:
        case SYM_BRC:
        {
            char const* str =  keycode == SYM_CBR ? "{}" :
                              (keycode == SYM_PRN ? "()" : "[]");
            if (record->event.pressed) {
                shifted = get_mods() & MOD_SHIFT_MASK;
                if (shifted) {
                    // Otherwise [] becomes {}
                    unregister_mods(MOD_SHIFT_MASK);
                }
                send_string(str);
                if (shifted) {
                    SEND_STRING(SS_TAP(X_LEFT));
                }
            } else {
                if (shifted) {
                    register_mods(MOD_BIT(KC_LSHIFT));
                }
            }
            return false;
        }
    }
    return true;
}
