#include QMK_KEYBOARD_H
#include "version.h"

enum rcj_layers {
  _QWERTY = 0,
  _FFXIV,
  _MOVEMENT,
  _MOVEMENT_FFXIV,
  _BRACES,
  _SYMBOLS,
  _ADJUST
};

enum rcj_keycodes {
  QWERTY = SAFE_RANGE,
  SYM_CBR,
  SYM_PRN,
  SYM_BRC,
  FF_1,
  FF_2,
  FF_3,
  FF_4,
  FF_5,
  FF_6,
  FF_7,
  FF_8,
  FF_9,
  FF_0,
  FF_Q,
  FF_W,
  FF_R,
  FF_T,
  FF_A,
  FF_G,
  FF_Z,
  FF_X,
  FF_V,
  FF_B,
  FF_Y,
  FF_H,
  FF_J,
  FF_K,
  FF_L,
  FF_N,
  FF_M,
  FF_COMM,
  FF_DOT,
  FF_LSFTF,
  FF_RECD
};

#define MOD_SHIFT_MASK  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define MOD_CTRL_MASK   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MOD_ALT_MASK    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define LEADER LCTL(KC_T)
#define SLCTL_T(kc) MT((MOD_LCTL | MOD_LGUI), kc)
#define SLALT_T(kc) MT((MOD_LCTL | MOD_LALT), kc)
#define KC_CME MT((MOD_LCTL | MOD_LALT), KC_ENT)
#define KC_SCD MT((MOD_LGUI | MOD_LCTL), KC_DEL)
#define KC_ZMV LT(_MOVEMENT, KC_Z)
#define KC_MOV MO(_MOVEMENT)
#define KC_MXIV MO(_MOVEMENT_FFXIV)
#define KC_SS MT(MOD_LSFT, KC_SPACE)
#define KC_BRSL LT(_BRACES, KC_SLSH)
#define KC_SYM MO(_SYMBOLS)
#define KC_SBUF MEH(KC_B)
#define KC_PREF MEH(KC_U)
#define KC_SWIN MEH(KC_N)
#define KC_ADJT MO(_ADJUST)
#define KC_DQOT MEH(KC_Q)
#define KC_DBRK MEH(KC_R)
#define KC_DBRC MEH(KC_F)
#define KC_DCRL MEH(KC_C)
#define KC_ANGL MEH(KC_M)
#define KC_DBUG DB_TOGG
#define KC_RST QK_BOOT
#define KC_SBRC SYM_BRC
#define KC_SPRN SYM_PRN
#define KC_SCBR SYM_CBR

#define KC_ KC_TRNS
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
 * | GUI        |   Z  |   X  |   C  |    V    |   B  |      |           |      |   N  |   M   |   ,  |   .  |BRCS/SLSH| HYPER        |
 * `------------+------+------+------+---------+-------------'           `-------------+-------+------+------+---------+--------------'
 *   | Esc      |      |      | NPAD |   Ctrl  |                                       |  Alt  | APP  |  GUI | ADJUST  | Esc          |
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
        KC_ESC,  KC_1,    KC_2,    KC_3,        KC_4,      KC_5,   _______,
        KC_TAB,  KC_Q,    KC_W,    KC_E,        KC_R,      KC_T,   _______,
        KC_CME,  KC_A,    KC_S,    KC_D,        KC_F,      KC_G,
        KC_LGUI, KC_Z,    KC_X,    KC_C,        KC_V,      KC_B,   _______,
        KC_ESC, _______, _______, KC_MOV,      KC_LCTL,
                                                     TG(_FFXIV), TG(_FFXIV),
                                                                    _______,
                                                   KC_SPC, KC_LALT, _______,
        // right hand
             _______, KC_6, KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
             _______, KC_Y, KC_U,    KC_I,    KC_O,    KC_P,    _______,
                      KC_H, KC_J,    KC_K,    KC_L,    KC_SYM,  KC_QUOT,
             _______, KC_N, KC_M,    KC_COMM, KC_DOT,  KC_BRSL, KC_HYPR,
                            KC_LALT, KC_APP,  KC_LGUI, MO(_ADJUST),          KC_ESC,
             _______, _______,
             _______,
             _______, LCTL(KC_C), KC_LSFT
    ),
[_FFXIV] = LAYOUT_ergodox(
        // left hand
        KC_ESC, FF_1,    FF_2,    FF_3,        FF_4,      FF_5,   FF_RECD,
        KC_TAB, FF_Q,    FF_W,    KC_E,        FF_R,      FF_T,   FF_LSFTF,
        KC_CME, FF_A,    KC_S,    KC_D,        KC_F,      FF_G,
        KC_SCD, FF_Z,    FF_X,    KC_C,        FF_V,      FF_B,   _______,
        KC_ESC, _______, _______, KC_LALT,     KC_LCTL,
                                                   TG(_FFXIV), TG(_FFXIV),
                                                                    _______,
                                                   KC_SPC, KC_LALT, _______,
        // right hand
             _______, FF_6, FF_7,    FF_8,    FF_9,    FF_0,    KC_BSPC,
             FF_RECD, FF_Y, KC_U,    KC_I,    KC_O,    KC_P,    _______,
                      FF_H, FF_J,    FF_K,    FF_L,    KC_MXIV,  KC_QUOT,
             KC_EQL,  FF_N, FF_M,    FF_COMM, FF_DOT,  KC_BRSL, KC_HYPR,
                            KC_ALCT,KC_LGUI, KC_LGUI, MO(_ADJUST),          KC_ESC,
             _______, _______,
             _______,
             _______, FF_0,    KC_LSFT
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
       _______, KC_SWIN, KC_HASH, KC_CIRC, KC_DLR, _______, _______,
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
       _______,  KC_F6,   KC_F7, KC_F8, KC_F9, KC_F10,  KC_F11,
       _______,  KC_0,    KC_7,  KC_8,  KC_9,  KC_PMNS, KC_F12,
                 KC_DOT,  KC_4,  KC_5,  KC_6,  KC_PPLS, KC_F13,
       _______,  KC_COMM, KC_1,  KC_2,  KC_3,  KC_PAST, KC_F14,
                          _______, _______, _______, _______, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
[_MOVEMENT_FFXIV] = LAYOUT_ergodox(
       _______, KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     _______,
       _______, MEH(KC_Q), MEH(KC_W), KC_E,      MEH(KC_R), MEH(KC_T), MEH(KC_F1),
       _______, MEH(KC_A), KC_S,      KC_D,      KC_F,      MEH(KC_G),
       _______, MEH(KC_Z), MEH(KC_X), MEH(KC_C), KC_ENT,    MEH(KC_B), MEH(KC_F2),
       _______, _______,   _______, _______, _______,
                                               _______, _______,
                                                        _______,
                                  MEH(KC_SPC), _______, _______,
    // right hand
       _______,  KC_F6,     KC_F7,     KC_F8,     KC_F9,     KC_F10,  KC_F11,
       _______,  MEH(KC_0), MEH(KC_7), MEH(KC_8), MEH(KC_9), _______, _______,
                 MEH(KC_H), MEH(KC_4), MEH(KC_5), MEH(KC_6), _______, _______,
       _______,  MEH(KC_N), MEH(KC_1), MEH(KC_2), MEH(KC_3), _______, _______,
                            _______,   _______,    _______,  _______, _______,
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
       _______, KC_RST,  KC_DBUG,   _______, _______, _______, _______,
       _______, QWERTY,  _______, AU_ON,   AU_OFF,  AG_NORM,
       KC_DBUG,   MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   _______,
       KC_RST ,   _______, _______, _______, _______,
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
static uint16_t key_to_repeat = 0;
static uint32_t repeat_timer = 0;

uint16_t get_key_to_repeat(uint16_t keycode) {
    switch (keycode) {
        case FF_Q: return KC_Q;
        case FF_W: return KC_W;
        case FF_R: return KC_R;
        case FF_T: return KC_T;
        case FF_A: return KC_A;
        case FF_G: return KC_G;
        case FF_Z: return KC_Z;
        case FF_X: return KC_X;
        case FF_V: return KC_V;
        case FF_B: return KC_B;
        case FF_Y: return KC_Y;
        case FF_H: return KC_H;
        case FF_J: return KC_J;
        case FF_K: return KC_K;
        case FF_L: return KC_L;
        case FF_N: return KC_N;
        case FF_M: return KC_M;
        case FF_COMM: return KC_COMM;
        case FF_DOT: return KC_DOT;
        case FF_1: return KC_1;
        case FF_2: return KC_2;
        case FF_3: return KC_3;
        case FF_4: return KC_4;
        case FF_5: return KC_5;
        case FF_6: return KC_6;
        case FF_7: return KC_7;
        case FF_8: return KC_8;
        case FF_9: return KC_9;
        case FF_0: return KC_0;
    }
    return 0;
}

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
                    register_mods(MOD_BIT(KC_LSFT));
                }
            }
            return false;
        }
        case FF_Q:
        case FF_W:
        case FF_R:
        case FF_T:
        case FF_A:
        case FF_G:
        case FF_Z:
        case FF_X:
        case FF_V:
        case FF_B:
        case FF_Y:
        case FF_H:
        case FF_J:
        case FF_K:
        case FF_L:
        case FF_N:
        case FF_M:
        case FF_COMM:
        case FF_DOT:
        case FF_1:
        case FF_2:
        case FF_3:
        case FF_4:
        case FF_5:
        case FF_6:
        case FF_7:
        case FF_8:
        case FF_9:
        case FF_0:
        {
            if (record->event.pressed) {
                key_to_repeat = get_key_to_repeat(keycode);
                register_code(key_to_repeat);
                unregister_code(key_to_repeat);
                repeat_timer = timer_read32();
              } else {
                  if (key_to_repeat == get_key_to_repeat(keycode))
                      key_to_repeat = 0;
            }
            return false;
        }
        case FF_LSFTF:
        {
            if (record->event.pressed) {
                register_code(KC_LSFT);
                register_code(KC_F);
            } else {
                unregister_code(KC_F);
                unregister_code(KC_LSFT);
            }
            return false;
        }
        case FF_RECD:
        {
            if (record->event.pressed) {
                register_code(KC_LGUI);
                register_code(KC_LALT);
                register_code(KC_R);
            } else {
                unregister_code(KC_R);
                unregister_code(KC_LALT);
                unregister_code(KC_LGUI);
            }
            return false;
        }
    }
    return true;
}

void matrix_scan_user(void) {
    if (key_to_repeat && timer_elapsed32(repeat_timer) > 100) {
        register_code(key_to_repeat);
        unregister_code(key_to_repeat);
        repeat_timer = timer_read32();
    }
}
