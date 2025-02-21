#include QMK_KEYBOARD_H
#include "version.h"
#include "features/achordion.h"
#include "features/autocorrection.h"
#include "features/select_word.h"
#include "features/sentence_case.h"
#include "features/custom_shift_keys.h"

#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  SELWORD = SAFE_RANGE,
  SELLINE,
  SELWFWD,
  SELWBAK,
  ST_MACRO_0,
  COMBO_ACTION,
  RGB_SLD = ML_SAFE_RANGE,
};

#include "features/custom_shift_keys.h"

const custom_shift_key_t custom_shift_keys[] = {
  {MT(MOD_RCTL, KC_DOT), KC_QUES}, // Shift . is ?
  {KC_COMM, KC_EXLM}, // Shift , is !
  {KC_UNDS, KC_MINS}, // Shift _ is -
  {MT(MOD_RALT, KC_EQUAL), KC_COLN}, // Shift = is : 
  {KC_SLSH, KC_BSLS}, // Shift / is inverted
  {KC_LPRN, KC_RPRN}, // Shift ( is )
  {KC_LBRC, KC_RBRC}, // Shift { is }
  {KC_LBRC, KC_RBRC}, // Shift [ is ]
};

uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(custom_shift_key_t);


uint16_t SELECT_WORD_KEYCODE = SELWORD;

void housekeeping_task_user(void) {
  achordion_task();
}

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_TRANSPARENT, CW_TOGG,        KC_TRANSPARENT, KC_MEDIA_PREV_TRACK,KC_MEDIA_PLAY_PAUSE,KC_MEDIA_NEXT_TRACK,                                KC_AUDIO_VOL_DOWN,KC_AUDIO_MUTE,  KC_AUDIO_VOL_UP,LALT(KC_E),     ST_MACRO_0,     KC_MEH,         
    LT(3,KC_TAB),   KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_SLASH,       
    ALL_T(KC_BSPC), MT(MOD_LALT, KC_A),LT(1,KC_S),     MT(MOD_LSFT, KC_D),LT(2,KC_F),     KC_G,                                           KC_H,           LT(3,KC_J),     MT(MOD_RSFT, KC_K),LT(1,KC_L),     MT(MOD_RALT, KC_EQUAL),MEH_T(KC_QUOTE),
    KC_COLN,        KC_Z,           MT(MOD_LCTL, KC_X),KC_C,           MT(MOD_LGUI, KC_V),KC_B,                                           KC_N,           MT(MOD_RGUI, KC_M),KC_COMMA,       MT(MOD_RCTL, KC_DOT),KC_UNDS,        KC_TRANSPARENT, 
                                                    LT(4,KC_ENTER), MT(MOD_LCTL, KC_ESCAPE),                                QK_REP, KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_SLASH,       KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_AMPR,        KC_HASH,        KC_LBRC,        KC_RBRC,        KC_AT,          KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_EXLM,        KC_MINUS,       KC_PLUS,        KC_QUES,        KC_EQUAL,                                       KC_PIPE,        KC_CIRC,        KC_LPRN,        KC_RPRN,        KC_DLR,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_LABK,        KC_RABK,        KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TILD,        KC_GRAVE,       KC_LCBR,        KC_RCBR,        KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_LLCK
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(KC_R),     RGUI(KC_PAGE_UP),RGUI(KC_PGDN),  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_BSPC,        LGUI(KC_Z),     KC_TRANSPARENT, KC_DELETE,      KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_LEFT_ALT,    KC_LEFT_GUI,    KC_LEFT_SHIFT,  KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       LGUI(KC_F),     KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(KC_LBRC),  KC_PAGE_UP,     KC_PGDN,        KC_TRANSPARENT, KC_TRANSPARENT,                                 SELWBAK, KC_TRANSPARENT, KC_TRANSPARENT, SELWFWD, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_LLCK
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_SLASH,       KC_9,           KC_8,           KC_7,           KC_ASTR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_E,           KC_HYPR,        KC_MEH,         KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_MINUS,       KC_3,           KC_2,           KC_1,           KC_PLUS,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_SHIFT, KC_RIGHT_GUI,   KC_RIGHT_ALT,   KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_PERC,        KC_6,           KC_5,           KC_4,           KC_X,                                           KC_TRANSPARENT, KC_TRANSPARENT, KC_COMMA,       KC_DOT,         KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_HYPR,        MEH_T(KC_0),                                    KC_TRANSPARENT, QK_LLCK
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, RGUI(KC_A),     RGUI(KC_X),     RGUI(KC_C),     RGUI(KC_V),     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    RGUI(KC_S),     RGUI(KC_Q),     RGUI(KC_W),     KC_GRAVE,       KC_MS_BTN3,     KC_MS_ACCEL2,                                   KC_MS_WH_RIGHT, KC_MS_WH_UP,    KC_MS_WH_DOWN,  KC_MS_WH_LEFT,  KC_TRANSPARENT, KC_TRANSPARENT, 
    RCTL(KC_UP),    KC_LEFT_SHIFT,  KC_LEFT_GUI,    KC_TAB,         TD(DANCE_0),    KC_MS_ACCEL1,                                   KC_MS_LEFT,     KC_MS_DOWN,     KC_MS_UP,       KC_MS_RIGHT,    KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, RGUI(KC_Z),     KC_MS_BTN4,     KC_MS_BTN5,     TD(DANCE_1),    KC_MS_ACCEL0,                                   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, QK_LLCK
  ),
};


enum combo_events {
    COMBO_N_TILDE,
    COMBO_SPANISH_TILDE,
};

const uint16_t PROGMEM combo0[] = { MT(MOD_LSFT, KC_D), MT(MOD_RSFT, KC_K), COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_COMMA, MT(MOD_RCTL, KC_DOT), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_N, LALT(KC_A), COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_QUOT, LALT(KC_A), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [0] = COMBO(combo0, KC_CAPS),
    [1] = COMBO(combo1, KC_SCLN),
    [COMBO_N_TILDE] = COMBO_ACTION(combo2),
    [COMBO_SPANISH_TILDE] = COMBO_ACTION(combo3),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
    switch (combo_index) {
        case COMBO_N_TILDE:
            if (pressed) {
                tap_code16(LALT(KC_N));  // Send Alt+n (dead tilde key)
                tap_code(KC_N);          // Follow up with 'n' to produce ñ
            }
            break;
        case COMBO_SPANISH_TILDE:
            if (pressed) {
                tap_code16(LALT(KC_E));  // Send Alt+e to produce the tilde
            }
            break;
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPACE:
            return TAPPING_TERM + 25;
        default:
            return TAPPING_TERM;
    }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t* record) {
  // If you quickly hold a tap-hold key after tapping it, the tap action is
  // repeated. Key repeating is useful e.g. for Vim navigation keys, but can
  // lead to missed triggers in fast typing. Here, returning 0 means we
  // instead want to "force hold" and disable key repeating.
  switch (keycode) {
    case KC_H:  // Assuming H is used for left navigation
    case LT(3, KC_J):  // J is used for down navigation
    case MT(MOD_RSFT, KC_K):  // K is used for up navigation
    case LT(1, KC_L):  // L is used for right navigation
      return QUICK_TAP_TERM;  // Enable key repeating.
    default:
      return 0;  // Otherwise, force hold and disable key repeating.
  }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [2] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {188,255,255}, {188,255,255}, {188,255,255}, {188,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0} },

    [4] = { {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,218,204}, {0,0,157}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,157}, {31,218,204}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {39,218,204}, {39,218,204}, {39,218,204}, {39,218,204}, {0,0,0}, {0,0,0}, {43,255,255}, {43,255,255}, {43,255,255}, {43,255,255}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {0,0,0}, {31,218,204}, {0,0,0} },

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

bool achordion_chord(uint16_t tap_hold_keycode,
                     keyrecord_t* tap_hold_record,
                     uint16_t other_keycode,
                     keyrecord_t* other_record) {
  // Exceptionally consider LT(4, KC_ENTER) + KC_MS_BTN1 as a hold.
  switch (tap_hold_keycode) {
    case LT(4, KC_ENTER):
      if (other_keycode == KC_MS_BTN1) { return true; }
      break;

    case KC_MS_BTN1:
      if (other_keycode == LT(4, KC_ENTER)) { return true; }
      break;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) { return true; }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_sentence_case(keycode, record)) { return false; }
    if (!process_achordion(keycode, record)) { return false; }
    if (!process_autocorrection(keycode, record)) { return false; }
    if (!process_select_word(keycode, record)) { return false; }
    if (!process_custom_shift_keys(keycode, record)) { return false; }

    switch (keycode) {
        case ST_MACRO_0:
            if (record->event.pressed) {
              SEND_STRING(SS_LALT(SS_TAP(X_N)) SS_DELAY(100) SS_TAP(X_N));
            }
            break;
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
            if (record->event.pressed) {
                select_word_register('L');
            } else {
                select_word_unregister();
            }
            break;

        case RGB_SLD:
            if (record->event.pressed) {
                rgblight_mode(1);
            }
            break;

        case KC_BSPC: {
            static uint16_t registered_key = KC_NO;
            if (record->event.pressed) {  // On key press.
                const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
                uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
                uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
                if (shift_mods) {  // At least one shift key is held.
                    registered_key = KC_DEL;
                    // If one shift is held, clear it from the mods. But if both
                    // shifts are held, leave as is to send Shift + Del.
                    if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
                        del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
                        unregister_mods(MOD_MASK_SHIFT);
                    }
                } else {
                    registered_key = KC_BSPC;
                }

                register_code(registered_key);
                set_mods(mods);
            } else {  // On key release.
                unregister_code(registered_key);
            }
        } return false;
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

static tap dance_state[2];

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
        tap_code16(KC_MS_BTN1);
        tap_code16(KC_MS_BTN1);
        tap_code16(KC_MS_BTN1);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN1);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN1); break;
        case SINGLE_HOLD: register_code16(KC_MS_BTN1); break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN1); register_code16(KC_MS_BTN1); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN1); register_code16(KC_MS_BTN1);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN1); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_BTN1); break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN1); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN1); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
        tap_code16(KC_MS_BTN2);
    }
    if(state->count > 3) {
        tap_code16(KC_MS_BTN2);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_MS_BTN2); break;
        case SINGLE_HOLD: register_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: register_code16(KC_MS_BTN2); register_code16(KC_MS_BTN2); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_MS_BTN2); register_code16(KC_MS_BTN2);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
        case SINGLE_HOLD: unregister_code16(KC_MS_BTN2); break;
        case DOUBLE_TAP: unregister_code16(KC_MS_BTN2); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_MS_BTN2); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};


bool achordion_eager_mod(uint8_t mod) {
  switch (mod) {
    case MOD_LSFT:
    case MOD_RSFT:
    case MOD_LCTL:
    case MOD_RCTL:
    case MOD_LGUI:  // Eagerly apply Left GUI (Command) mod for Mac.
    case MOD_RGUI:  // Eagerly apply Right GUI (Command) mod for Mac.
      return true;  // Eagerly apply these mods.

    default:
      return false;
  }
}

uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    // Add your thumb keys here
    case LT(4, KC_ENTER):  // Example thumb key
    case MT(MOD_LCTL, KC_ESCAPE):  // Example thumb key
    case QK_REP:  // Example thumb key
    case KC_SPACE:  // Example thumb key
      return 0;  // Bypass Achordion for these keys.
  }

  return 800;  // Otherwise use a timeout of 800 ms.
}
