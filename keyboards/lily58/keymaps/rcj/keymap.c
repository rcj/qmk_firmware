#include QMK_KEYBOARD_H

#include <stdio.h>

#define MOD_SHIFT_MASK  (MOD_BIT(KC_LSFT)|MOD_BIT(KC_RSFT))
#define MOD_CTRL_MASK   (MOD_BIT(KC_LCTL)|MOD_BIT(KC_RCTRL))
#define MOD_ALT_MASK    (MOD_BIT(KC_LALT)|MOD_BIT(KC_RALT))

#ifdef KC_LEAD
#undef KC_LEAD
#endif
#define KC_LEAD LCTL(KC_T)
#define KC_SAE MT((MOD_LGUI | MOD_LALT), KC_ENT)
#define KC_SCD MT((MOD_LGUI | MOD_LCTL), KC_DEL)
#define KC_MOV MO(_MOVEMENT)
#define KC_MOVE TG(_MOVEMENT)
#define KC_MAC TG(_QWERTY)
#define KC_WIN TG(_QWERTY_WIN)
#define KC_SS MT(MOD_LSFT, KC_SPACE)
#define KC_BRSL LT(_BRACES, KC_SLSH)
#define KC_SYM MO(_SYMBOLS)
#define KC_WSYM MO(_SYMBOLS_WIN)
#define KC_SBUF MEH(KC_B)
#define KC_PREF MEH(KC_U)
#define KC_SWIN MEH(KC_N)
#define KC_DQOT MEH(KC_Q)
#define KC_DBRK MEH(KC_R)
#define KC_DBRC MEH(KC_F)
#define KC_DCRL MEH(KC_C)
#define KC_ANGL MEH(KC_M)
#define KC_MSBUF LCAG(KC_B)
#define KC_MPREF LCAG(KC_U)
#define KC_MSWIN LCAG(KC_N)
#define KC_MDQOT LCAG(KC_Q)
#define KC_MDBRK LCAG(KC_R)
#define KC_MDBRC LCAG(KC_F)
#define KC_MDCRL LCAG(KC_C)
#define KC_MANGL LCAG(KC_M)
#define KC_SBRC SYM_BRC
#define KC_SPRN SYM_PRN
#define KC_SCBR SYM_CBR

#define KC_ KC_TRNS
#define _______ KC_TRNS

enum layer_number {
  _QWERTY = 0,
  _QWERTY_WIN,
  _MOVEMENT,
  _BRACES,
  _SYMBOLS,
  _SYMBOLS_WIN,
  _ADJUST

};

enum rcj_keycodes {
  QWERTY = SAFE_RANGE,
  SYM_CBR,
  SYM_PRN,
  SYM_BRC
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                             KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_RALT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_SAE ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                             KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_SYM , KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_SCD ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_ENT,          KC_ENT ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_BRSL, KC_HYPR,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                            KC_MOV , KC_MOV , KC_LCTL,  KC_SPC,                   KC_LSFT, KC_LGUI, KC_LALT, KC_APP
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

    [_QWERTY_WIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_ESC ,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,                             KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_BSPC,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_TAB ,  KC_Q  ,  KC_W  ,  KC_E  ,  KC_R  ,  KC_T  ,                             KC_Y  ,  KC_U  ,  KC_I  ,  KC_O  ,  KC_P  , KC_RALT,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_SAE ,  KC_A  ,  KC_S  ,  KC_D  ,  KC_F  ,  KC_G  ,                             KC_H  ,  KC_J  ,  KC_K  ,  KC_L  , KC_WSYM, KC_QUOT,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_SCD ,  KC_Z  ,  KC_X  ,  KC_C  ,  KC_V  ,  KC_B  ,  KC_ENT,          KC_ENT ,  KC_N  ,  KC_M  , KC_COMM, KC_DOT , KC_BRSL, KC_HYPR,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                           KC_MOV , KC_MOV , KC_LCTL,  KC_SPC,                   KC_LSFT, KC_LALT, KC_APP , KC_LGUI
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

      [_SYMBOLS] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_PERC,KC_MDQOT, KC_BSLS,  KC_EQL,KC_MDBRK, KC_TILD,                            KC_PIPE,KC_MPREF,  KC_TAB, KC_BSPC, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ASTR, KC_MINS, KC_UNDS, KC_COLN,KC_MDBRC,  KC_GT ,                            KC_AMPR, KC_SCLN, KC_EXLM,  KC_LT , _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_MANGL, KC_PLUS,  KC_AT ,KC_MDCRL,  KC_ENT,KC_MSBUF, _______,          _______,KC_MSWIN, KC_HASH, KC_CIRC,  KC_DLR, _______, _______,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                            _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

      [_SYMBOLS_WIN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_GRV , KC_EXLM,  KC_AT , KC_HASH,  KC_DLR, KC_PERC,                            KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_PERC, KC_DQOT, KC_BSLS,  KC_EQL, KC_DBRK, KC_TILD,                            KC_PIPE, KC_PREF,  KC_TAB, KC_BSPC, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ASTR, KC_MINS, KC_UNDS, KC_COLN, KC_DBRC,  KC_GT ,                            KC_AMPR, KC_SCLN, KC_EXLM,  KC_LT , _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      KC_ANGL, KC_PLUS,  KC_AT , KC_DCRL,  KC_ENT, KC_SBUF, _______,          _______, KC_SWIN, KC_HASH, KC_CIRC,  KC_DLR, _______, _______,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                            _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),
  // SBUF = LGUI+B (Switch Buffer) | PREF = LGUI+U (Prefix Key) | SWIN = LGUI+N (Switch Window)

  [_MOVEMENT] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,                             KC_F6 ,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, KC_PGUP,  KC_UP , KC_PGDN, KC_HOME,                             KC_0  ,  KC_7  ,  KC_8  ,  KC_9  , _______, KC_F12 ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_LSFT, KC_LEFT, KC_DOWN, KC_RGHT, KC_END ,                            KC_DOT ,  KC_4  ,  KC_5  ,  KC_6  , _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, KC_LCTL, KC_INS , _______, _______, KC_PSCR, _______,          _______, KC_COMM,  KC_1  ,  KC_2  ,  KC_3  , _______, _______,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                            _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

  [_BRACES] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      KC_VOLU, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, RGB_TOG,                            _______, _______, _______, _______, _______, KC_MAC ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_VOLD, _______, KC_SBRC, KC_LBRC, KC_RBRC, _______,                           _______,  KC_PGUP,  KC_UP , KC_PGDN, _______, KC_WIN ,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      KC_MUTE, _______, KC_SPRN, KC_LPRN, KC_RPRN, _______,                            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, KC_SCBR, KC_LCBR, KC_RCBR, _______, _______,          _______, _______, KC_ENT , _______, KC_TAB , _______, _______,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                            _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  ),

  [_ADJUST] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //└────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┘
                            _______, _______, _______, _______,                   _______, _______, _______, _______
                       // └────────┴────────┴────────┴────────┘                 └────────┴────────┴────────┴────────┘
  )

};

//SSD1306 OLED update loop, make sure to enable OLED_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

char layer_state_str[24];

#define L_MACOS 0
#define L_WIN (1 << 1)
#define L_MOVEMENT (1 << 2)
#define L_BRACES (1 << 3)
#define L_SYMBOLS (1 << 4)
#define L_SYMBOLS_WIN (1 << 5)
#define L_ADJUST (1 << 6)

const char *rcj_read_layer_state(void) {
  switch (layer_state)
  {
  case L_MACOS:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: MacOS");
    break;
  case L_WIN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Windows");
    break;
  case L_MOVEMENT:
  case L_MOVEMENT | L_WIN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Movement");
    break;
  case L_BRACES:
  case L_BRACES | L_WIN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Braces");
    break;
  case L_SYMBOLS:
  case L_SYMBOLS | L_WIN:
  case L_SYMBOLS_WIN | L_WIN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Symbols");
    break;
  case L_ADJUST:
  case L_ADJUST | L_WIN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%u", layer_state);
  }

  return layer_state_str;
}


bool oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(rcj_read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);
    //oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    oled_write(read_logo(), false);
  }
    return false;
}
#endif // OLED_ENABLE

static bool shifted = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_ENABLE
    //set_keylog(keycode, record);
#endif
  }
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
  }
  return true;
}
