#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

#define MOD_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MOD_CTRL_MASK   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MOD_ALT_MASK    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define KC_LEAD LCTL(KC_T)
#define KC_SAE MT((MOD_LGUI | MOD_LALT), KC_ENT)
#define KC_SCD MT((MOD_LGUI | MOD_LCTL), KC_DEL)
#define KC_ZNP LT(_NUMPAD, KC_Z)
#define KC_MOV MO(_MOVEMENT)
#define KC_MOVE TG(_MOVEMENT)
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
#define KC_LCAT LCA_T(KC_NO)

#define KC_ KC_TRNS
#define _______ KC_TRNS
#define XXXXXXX KC_NO

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum rcj_layers {
  _QWERTY,
  _NUMPAD,
  _MOVEMENT,
  _BRACES,
  _SYMBOLS
};

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  SYM_CBR,
  SYM_PRN,
  SYM_BRC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | SAE  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  | QUOT |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SCD  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  | HYPR |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | ESC  |      |      | MOV  | LCTL | SPC  | SHFT | LALT | LGUI |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT( \
  KC_TAB, KC_Q,    KC_W,    KC_E,   KC_R,    KC_T,   KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_SAE, KC_A,    KC_S,    KC_D,   KC_F,    KC_G,   KC_H,    KC_J,    KC_K,    KC_L,    KC_SYM,  KC_QUOT,  \
  KC_SCD, KC_Z,    KC_X,    KC_C,   KC_V,    KC_B,   KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_BRSL, KC_HYPR, \
  KC_ESC, _______, _______, KC_MOV, KC_LCTL, KC_SPC, KC_LSFT, KC_LALT, KC_LGUI, _______, _______, _______  \
),

[_SYMBOLS] = LAYOUT( \
  KC_PERC, KC_DQOT, KC_BSLS, KC_EQL,  KC_DBRK, KC_TILD, KC_PIPE, KC_PREF, KC_TAB,  KC_BSPC, _______, _______, \
  KC_ASTR, KC_MINS, KC_UNDS, KC_COLN, KC_DBRC, KC_GT,   KC_AMPR, KC_SCLN, KC_EXLM, KC_LT,   _______, _______, \
  KC_ANGL, KC_PLUS, KC_AT,   KC_DCRL, KC_ENT,  KC_SBUF, KC_SWIN, KC_HASH, KC_DLR,  KC_CIRC, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_MOVEMENT] = LAYOUT( \
  _______, _______, KC_PGUP, KC_UP,   KC_PGDN, KC_HOME, KC_0,    KC_7,    KC_8,    KC_9,    _______, _______, \
  _______, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END,  KC_DOT,  KC_4,    KC_5,    KC_6,    _______, _______, \
  _______, KC_LCTL, KC_INS,  _______, _______, KC_PSCR, KC_COMM, KC_1,    KC_2,    KC_3,    _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \
),

[_BRACES] = LAYOUT( \
  _______, _______, KC_SBRC, KC_LBRC, KC_RBRC, _______, _______, _______, KC_UP,   KC_TAB,  _______, RESET,   \
  _______, _______, KC_SPRN, KC_LPRN, KC_RPRN, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, \
  _______, _______, KC_SCBR, KC_LCBR, KC_RCBR, _______, _______, KC_ENT,  _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______  \

),

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool shifted = false;

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
