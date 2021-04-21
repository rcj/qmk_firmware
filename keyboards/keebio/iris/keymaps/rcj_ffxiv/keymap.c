#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

#define MOD_SHIFT_MASK  (MOD_BIT(KC_LSHIFT)|MOD_BIT(KC_RSHIFT))
#define MOD_CTRL_MASK   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MOD_ALT_MASK    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#define KC_LEAD LCTL(KC_T)
#define KC_SAE MT((MOD_LGUI | MOD_LALT), KC_ENT)
#define KC_SCD MT((MOD_LGUI | MOD_LCTL), KC_DEL)
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
#define KC_FF_2 FF_2
#define KC_FF_3 FF_3
#define KC_FF_4 FF_4
#define KC_FF_5 FF_5
#define KC_FF_Q FF_Q
#define KC_FF_W FF_W
#define KC_FF_R FF_R
#define KC_FF_T FF_T
#define KC_FF_A FF_A
#define KC_FF_G FF_G
#define KC_FF_Z FF_Z
#define KC_FF_X FF_X
#define KC_FF_C FF_C
#define KC_FF_V FF_V
#define KC_FF_B FF_B

#define KC_ KC_TRNS
#define _______ KC_TRNS

extern keymap_config_t keymap_config;

enum rcj_layers {
  _QWERTY,
  _MOVEMENT,
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
  FF_Q,
  FF_W,
  FF_R,
  FF_T,
  FF_A,
  FF_G,
  FF_Z,
  FF_X,
  FF_C,
  FF_V,
  FF_B
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , FF_1 , FF_2  , FF_3  , FF_4  , FF_5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , FF_Q  , FF_W  , E  , FF_R  , FF_T  ,                Y  , U  , I  , O  , P  ,RALT,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     SAE , FF_A  , S  , D  , F  , FF_G  ,                H  , J  , K  , L  ,SYM ,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     SCD , FF_Z  , FF_X  , FF_C  , FF_V  , FF_B  , SPC,     LSFT, N  , M  ,COMM,DOT ,BRSL,HYPR,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LALT ,LCTL, SPC ,       LSFT ,LALT,LGUI
  //                  `----+----+----'        `----+----+----'
  ),
  // SAE = Super+LALT/Enter | SCD = Super+LCTL/DEL
  // MOVE = Toggle Movement+Fkeys | SYM = Symbols | BRSL = Braces/Slash

  [_SYMBOLS] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     GRV ,EXLM, AT ,HASH, DLR,PERC,               CIRC,AMPR,ASTR,LPRN,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     PERC,DQOT,BSLS, EQL,DBRK,TILD,               PIPE,PREF, TAB,BSPC,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     ASTR,MINS,UNDS,COLN,DBRC, GT ,               AMPR,SCLN,EXLM, LT ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     ANGL,PLUS, AT ,DCRL, ENT,SBUF,    ,         ,SWIN,HASH, DLR,CIRC,    ,    ,
  //`----+----+----+----+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,     ,            ,    ,
  //                  `----+----+----'        `----+----+-----'
  ),
  // SBUF = LGUI+B (Switch Buffer) | PREF = LGUI+U (Prefix Key) | SWIN = LGUI+N (Switch Window)

  [_MOVEMENT] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F11 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     F12 ,    ,PGUP, UP ,PGDN,HOME,                0  , 7  , 8  , 9  ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,LSFT,LEFT,DOWN,RGHT,END ,               DOT , 4  , 5  , 6  ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,LCTL,INS ,    ,    ,PSCR,    ,         ,COMM, 1  , 2  , 3  ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_BRACES] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ADJT,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,SBRC,LBRC,RBRC,    ,                   ,    , UP ,TAB ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,SPRN,LPRN,RPRN,    ,                   ,LEFT,DOWN,RGHT,    ,    ,
  //|----p+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
         ,    ,SCBR,LCBR,RCBR,    ,    ,         ,    ,ENT ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_ADJUST] = LAYOUT_kc(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     DBUG,    ,    ,    ,    ,    ,                   ,    ,    ,    ,    ,    ,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     RST ,    ,    ,    ,    ,    ,    ,         ,    ,    ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  )

};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

static bool shifted = false;
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
        case FF_C: return KC_C;
        case FF_V: return KC_V;
        case FF_B: return KC_B;
        case FF_1: return KC_1;
        case FF_2: return KC_2;
        case FF_3: return KC_3;
        case FF_4: return KC_4;
        case FF_5: return KC_5;
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
                    register_mods(MOD_BIT(KC_LSHIFT));
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
        case FF_C:
        case FF_V:
        case FF_B:
        case FF_1:
        case FF_2:
        case FF_3:
        case FF_4:
        case FF_5:
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
    return true;
}

void matrix_scan_user(void) {
    if (key_to_repeat && timer_elapsed32(repeat_timer) > 300) {
        register_code(key_to_repeat);
        unregister_code(key_to_repeat);
        repeat_timer = timer_read32();
    }
}
