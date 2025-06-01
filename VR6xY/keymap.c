#include QMK_KEYBOARD_H
#include "version.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
};



#define DUAL_FUNC_0 LT(6, KC_A)
#define DUAL_FUNC_1 LT(10, KC_F5)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,CW_TOGG,        KC_CAPS,        KC_ESCAPE,                                      KC_TRANSPARENT, ST_MACRO_0,     LALT(KC_E),     KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_SLASH,       
    LT(3, KC_BSPC), MT(MOD_LALT, KC_A),LT(1, KC_S),    MT(MOD_LSFT, KC_D),LT(2, KC_F),    ALL_T(KC_G),                                    KC_H,           LT(3, KC_J),    MT(MOD_RSFT, KC_K),LT(1, KC_L),    MT(MOD_RALT, KC_EQUAL),KC_QUOTE,       
    KC_NO,          KC_Z,           MT(MOD_LCTL, KC_X),MEH_T(KC_C),    MT(MOD_LGUI, KC_V),MEH_T(KC_B),                                    KC_N,           MT(MOD_RGUI, KC_M),KC_COMMA,       MT(MOD_RCTL, KC_DOT),KC_UNDS,        KC_TRANSPARENT, 
                                                    LT(4, KC_ENTER),KC_NO,                                          MEH_T(KC_ESCAPE),ALL_T(KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_SLASH,       KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_AMPR,        KC_HASH,        KC_LBRC,        KC_RBRC,        KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_TRANSPARENT, KC_PLUS,        KC_QUES,        KC_EQUAL,                                       KC_PIPE,        KC_CIRC,        KC_LPRN,        KC_TRANSPARENT, KC_DLR,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TILD,        KC_GRAVE,       KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_LLCK
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_CAPS,        RGUI(KC_R),     RGUI(KC_PAGE_UP),RGUI(KC_PGDN),  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_BSPC,        LGUI(KC_Z),     KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       LGUI(KC_F),     KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(KC_LBRC),  KC_PAGE_UP,     KC_PGDN,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_LLCK
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SLASH,       KC_9,           KC_8,           KC_7,           KC_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_E,           KC_HYPR,        KC_MEH,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MINUS,       KC_3,           KC_2,           KC_1,           KC_PLUS,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_6,           KC_5,           KC_4,           KC_X,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    ALL_T(KC_0),    KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_LLCK
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, RGUI(KC_A),     RGUI(KC_X),     RGUI(KC_C),     RGUI(KC_V),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGUI(KC_S),     RGUI(KC_Q),     RGUI(KC_W),     KC_GRAVE,       KC_MS_BTN3,     KC_MS_ACCEL2,                                   KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_LEFT,  KC_TRANSPARENT, KC_TRANSPARENT, 
    RCTL(KC_UP),    KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_TAB,         DUAL_FUNC_0,    KC_MS_ACCEL1,                                   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(KC_Z),     KC_MS_BTN4,     KC_MS_BTN5,     DUAL_FUNC_1,    KC_MS_ACCEL0,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};

const uint16_t PROGMEM combo0[] = { MT(MOD_LSFT, KC_D), MT(MOD_RSFT, KC_K), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_COMMA, MT(MOD_RCTL, KC_DOT), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_CAPS),
    COMBO(combo1, KC_SCLN),
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(4, KC_ENTER):
            return TAPPING_TERM + 25;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,218,204}, {0,0,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,157}, {0,0,0}, {31,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {39,218,204}, {39,218,204}, {39,218,204}, {39,218,204}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,218,204} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb( hsv );
        float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
        rgb_matrix_set_color( i, f * rgb.r, f * rgb.g, f * rgb.b );
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (keyboard_config.disable_layer_led) { return false; }
  switch (biton32(layer_state)) {
    case 2:
      set_layer_color(2);
      break;
    case 4:
      set_layer_color(4);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_TAP(X_N))SS_DELAY(100)  SS_TAP(X_N));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_MS_BTN1);
        } else {
          unregister_code16(KC_MS_BTN1);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_MS_BTN1);
        } else {
          unregister_code16(KC_MS_BTN1);
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_MS_BTN2);
        } else {
          unregister_code16(KC_MS_BTN2);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_MS_BTN2);
        } else {
          unregister_code16(KC_MS_BTN2);
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


