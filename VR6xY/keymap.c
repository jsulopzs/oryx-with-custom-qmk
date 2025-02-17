#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#include "features/autocorrection.h"
#include "features/select_word.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  RGB_SLD = ML_SAFE_RANGE,
};

uint16_t SELECT_WORD_KEYCODE = SELWORD;

void housekeeping_task_user(void) {
  achordion_task();
}

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,        
    KC_GRAVE,       MT(MOD_LCTL, KC_A),MT(MOD_LALT, KC_S),MT(MOD_LGUI, KC_D),MT(MOD_LSFT, KC_F),KC_G,                                           KC_H,           MT(MOD_RSFT, KC_J),MT(MOD_RGUI, KC_K),MT(MOD_RALT, KC_L),MT(MOD_RCTL, KC_SCLN),KC_QUOTE,       
    ALL_T(KC_CAPS), KC_Z,           KC_X,           TD(DANCE_0),    TD(DANCE_1),    KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         KC_SLASH,       KC_MEH,         
                                                    TD(DANCE_2),    LT(1,KC_ESCAPE),                                KC_BSPC,        LT(2,KC_SPACE)
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_BSPC,        KC_TRANSPARENT, KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, SELLINE, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, SELWBAK, SELWFWD, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_ENTER
  ),
  [2] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_GRAVE,       KC_EXLM,        KC_AT,          KC_HASH,        KC_DLR,         KC_PERC,                                        KC_7,           KC_8,           KC_9,           KC_MINUS,       KC_SLASH,       KC_F12,         
    KC_TILD,        KC_CIRC,        KC_AMPR,        KC_ASTR,        KC_LPRN,        KC_RPRN,                                        KC_4,           KC_5,           KC_6,           KC_PLUS,        KC_ASTR,        KC_BSPC,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,                                        KC_1,           KC_2,           KC_3,           TD(DANCE_3),    KC_EQUAL,       KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_0,                                           KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_Q),     LSFT(KC_GRAVE), KC_GRAVE,       KC_MS_BTN3,     KC_MS_ACCEL2,                                   KC_MS_WH_LEFT,  KC_MS_WH_DOWN,  KC_MS_WH_UP,    KC_MS_WH_RIGHT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RCTL(KC_UP),    KC_LEFT_GUI,    LSFT(KC_TAB),   KC_TAB,         TD(DANCE_4),    KC_MS_ACCEL1,                                   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, LGUI(KC_W),     KC_MS_BTN4,     KC_MS_BTN5,     TD(DANCE_5),    KC_MS_ACCEL0,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(2,KC_SPACE):
            return TAPPING_TERM + 40;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,245,245}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [3] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,218,204}, {0,0,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,157}, {31,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {39,218,204}, {39,218,204}, {39,218,204}, {39,218,204}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,218,204}, {0,0,0} },

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
    case 1:
      set_layer_color(1);
      break;
    case 3:
      set_layer_color(3);
      break;
   default:
    if (rgb_matrix_get_flags() == LED_FLAG_NONE)
      rgb_matrix_set_color_all(0, 0, 0);
    break;
  }
  return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_autocorrection(keycode, record)) { return false; }
  if (!process_select_word(keycode, record)) { return false; }

  switch (keycode) {
    case SELWBAK:  // Backward word selection.
      if (record->event.pressed) {
        select_word_register('B');
      } else {
        select_word_unregister();
      }
      break;

    case SELWFWD:  // Forward word selection.
      if (record->event.pressed) {
        select_word_register('W');
      } else {
        select_word_unregister();
      }
      break;

    case SELLINE:  // Line selection.
      if(record->event.pressed) {
        select_word_register('L');
      } else {
        select_word_unregister();
      }
      break;

  switch (keycode) {

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[6];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_C);
        tap_code16(KC_C);
        tap_code16(KC_C);
    }
    if(state->count > 3) {
        tap_code16(KC_C);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_C); break;
        case DOUBLE_TAP: register_code16(KC_C); register_code16(KC_C); break;
        case DOUBLE_HOLD: register_code16(RGUI(KC_C)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_C); register_code16(KC_C);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_TAP: unregister_code16(KC_C); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(KC_C)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_C); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_V);
        tap_code16(KC_V);
        tap_code16(KC_V);
    }
    if(state->count > 3) {
        tap_code16(KC_V);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_V); break;
        case DOUBLE_TAP: register_code16(KC_V); register_code16(KC_V); break;
        case DOUBLE_HOLD: register_code16(RGUI(KC_V)); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_V); register_code16(KC_V);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_TAP: unregister_code16(KC_V); break;
        case DOUBLE_HOLD: unregister_code16(RGUI(KC_V)); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_V); break;
    }
    dance_state[1].step = 0;
}
void on_dance_2(tap_dance_state_t *state, void *user_data);
void dance_2_finished(tap_dance_state_t *state, void *user_data);
void dance_2_reset(tap_dance_state_t *state, void *user_data);

void on_dance_2(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_2_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[2].step = dance_step(state);
    switch (dance_state[2].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case SINGLE_HOLD: layer_on(3); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_HOLD: register_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_2_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[2].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case SINGLE_HOLD:
          layer_off(3);
        break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_HOLD: unregister_code16(KC_LEFT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[2].step = 0;
}
void on_dance_3(tap_dance_state_t *state, void *user_data);
void dance_3_finished(tap_dance_state_t *state, void *user_data);
void dance_3_reset(tap_dance_state_t *state, void *user_data);

void on_dance_3(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
        tap_code16(KC_DOT);
    }
    if(state->count > 3) {
        tap_code16(KC_DOT);
    }
}

void dance_3_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[3].step = dance_step(state);
    switch (dance_state[3].step) {
        case SINGLE_TAP: register_code16(KC_DOT); break;
        case DOUBLE_TAP: register_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_DOT); register_code16(KC_DOT);
    }
}

void dance_3_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[3].step) {
        case SINGLE_TAP: unregister_code16(KC_DOT); break;
        case DOUBLE_TAP: unregister_code16(KC_COLN); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_DOT); break;
    }
    dance_state[3].step = 0;
}
void on_dance_4(tap_dance_state_t *state, void *user_data);
void dance_4_finished(tap_dance_state_t *state, void *user_data);
void dance_4_reset(tap_dance_state_t *state, void *user_data);

void on_dance_4(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MS_BTN1);
        tap_code16(KC_MS_BTN1);
        tap_code16(KC_MS_BTN1);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN1);
    }
}

void dance_4_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[4].step = dance_step(state);
    switch (dance_state[4].step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN1); break;
        case SINGLE_HOLD: register_code16(KC_MS_BTN1); break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN1); register_code16(KC_MS_BTN1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN1); register_code16(KC_MS_BTN1);
    }
}

void dance_4_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[4].step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN1); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_BTN1); break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN1); break;
    }
    dance_state[4].step = 0;
}
void on_dance_5(tap_dance_state_t *state, void *user_data);
void dance_5_finished(tap_dance_state_t *state, void *user_data);
void dance_5_reset(tap_dance_state_t *state, void *user_data);

void on_dance_5(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN2);
    }
}

void dance_5_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[5].step = dance_step(state);
    switch (dance_state[5].step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN2); break;
        case SINGLE_HOLD: register_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN2); register_code16(KC_MS_BTN2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN2); register_code16(KC_MS_BTN2);
    }
}

void dance_5_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[5].step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
    }
    dance_state[5].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
        [DANCE_2] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_2, dance_2_finished, dance_2_reset),
        [DANCE_3] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_3, dance_3_finished, dance_3_reset),
        [DANCE_4] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_4, dance_4_finished, dance_4_reset),
        [DANCE_5] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_5, dance_5_finished, dance_5_reset),
};
