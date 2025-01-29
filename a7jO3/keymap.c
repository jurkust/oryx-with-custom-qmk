#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

bool is_alt_tab_active = false;

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ALT_TAB,
  HSV_189_255_255,
};


typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
tap_dance_action_t *action;

enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
  DANCE_2,
  DANCE_3,
  DANCE_4,
  DANCE_5,
  DANCE_6,
  DANCE_7,
  DANCE_8,
  DANCE_9,
  DANCE_10,
  DANCE_11,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      TD(DANCE_0),    TD(DANCE_1),    TD(DANCE_2),    TD(DANCE_3),    TD(DANCE_4),                                    TD(DANCE_5),    TD(DANCE_6),    TD(DANCE_7),    KC_9,           KC_0,           TD(DANCE_8),    
    KC_TAB,         KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,                                           KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_MINUS,       
    KC_LEFT_SHIFT,  KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        MT(MOD_RSFT, KC_QUOTE),
    KC_LEFT_ALT,    KC_Z,           KC_X,           KC_C,           KC_V,           KC_B,                                           KC_N,           KC_M,           KC_COMMA,       KC_DOT,         TD(DANCE_9),    KC_RIGHT_ALT,   
                                                    MT(MOD_LCTL, KC_BSPC),MO(2),                                          LT(3,KC_ENTER), KC_SPACE
  ),
  [1] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_TRANSPARENT, KC_EQUAL,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_W,           KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_A,           KC_S,           KC_D,           KC_F,           KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_LEFT_CTRL,   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_SPACE,       KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    KC_TRANSPARENT, KC_TRANSPARENT, KC_AUDIO_MUTE,  KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,ALT_TAB,                                 KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_MINUS,    KC_KP_SLASH,    KC_F12,         
    CW_TOGG,        KC_TRANSPARENT, KC_TRANSPARENT, LALT(KC_TAB),   KC_TRANSPARENT, KC_SPACE,                                       KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_KP_ASTERISK, KC_NUM,         
    KC_TRANSPARENT, TD(DANCE_10),   KC_MEDIA_STOP,  KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,KC_MEDIA_PLAY_PAUSE,                                KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_DOT,         KC_KP_EQUAL,    QK_LLCK,        
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_KP_0
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, RGB_TOG,        TOGGLE_LAYER_COLOR,RGB_MODE_FORWARD,RGB_VAD,        RGB_VAI,                                        KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   KC_BSPC,        KC_DELETE,      
    KC_TRANSPARENT, KC_GRAVE,       KC_TILD,        KC_LBRC,        KC_RBRC,        ALT_TAB,                                        KC_PAGE_UP,     KC_HOME,        KC_UP,          KC_END,         KC_PSCR,        KC_NUBS,        
    KC_TRANSPARENT, AS_ON,          AS_OFF,         KC_LCBR,        KC_RCBR,        TD(DANCE_11),                                   KC_PGDN,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_TRANSPARENT, KC_GRAVE,       
    LSFT(KC_PC_UNDO),KC_PC_UNDO,     KC_PC_CUT,      KC_PC_COPY,     KC_PC_PASTE,    HSV_189_255_255,                                KC_QUES,        KC_TRANSPARENT, LALT(KC_SPACE), KC_TRANSPARENT, KC_BSLS,        QK_LLCK,        
                                                    MT(MOD_LALT, KC_BSPC),KC_LEFT_GUI,                                    KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_voyager(
    KC_TRANSPARENT, RALT(KC_1),     RALT(KC_2),     RALT(KC_3),     RALT(KC_4),     RALT(KC_5),                                     RALT(KC_6),     RALT(KC_7),     RALT(KC_8),     RALT(KC_9),     KC_TRANSPARENT, RALT(KC_EQUAL), 
    KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_EQUAL,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    MT(MOD_LALT, KC_BSPC),KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
};


uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(DANCE_10):
            return TAPPING_TERM + 840;
        default:
            return TAPPING_TERM;
    }
}

extern rgb_config_t rgb_matrix_config;

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [1] = { {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {139,255,255}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {139,255,255}, {139,255,255}, {139,255,255}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70}, {0,0,70} },

    [2] = { {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {189,255,255}, {189,255,255}, {139,128,255}, {189,255,255}, {139,128,255}, {139,128,255}, {189,255,255}, {99,255,255}, {0,218,204}, {139,128,255}, {139,128,255}, {139,128,255}, {139,128,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,255,255}, {139,255,255}, {189,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,255,255}, {139,255,255}, {189,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {139,255,255}, {189,255,255}, {0,218,204}, {189,255,255}, {0,0,255} },

    [3] = { {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {139,255,255}, {139,255,255}, {189,255,255}, {189,255,255}, {250,255,255}, {250,255,255}, {139,255,255}, {139,255,255}, {189,255,255}, {23,225,192}, {23,225,192}, {23,225,192}, {23,225,192}, {23,225,192}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {0,218,204}, {0,218,204}, {189,255,255}, {189,255,255}, {0,0,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {0,0,255}, {0,0,255}, {0,0,255}, {189,255,255}, {189,255,255}, {189,255,255}, {189,255,255}, {169,255,255}, {189,255,255}, {189,255,255}, {0,218,204}, {189,255,255}, {189,255,255} },

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
    case 2:
      set_layer_color(2);
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
  switch (keycode) {

    case TD(DANCE_0):
    case TD(DANCE_1):
    case TD(DANCE_2):
    case TD(DANCE_3):
    case TD(DANCE_4):
    case TD(DANCE_5):
    case TD(DANCE_6):
    case TD(DANCE_7):
    case TD(DANCE_8):
    case TD(DANCE_9):
    case TD(DANCE_10):
        action = &tap_dance_actions[TD_INDEX(keycode)];
        if (!record->event.pressed && action->state.count && !action->state.finished) {
            tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
            tap_code16(tap_hold->tap);
        }
        break;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
    case HSV_189_255_255:
      if (record->event.pressed) {
        rgblight_mode(1);
        rgblight_sethsv(189,255,255);
      }
      return false;
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
    case MO(2):
    case MO(3):
      if (is_alt_tab_active && !record->event.pressed) {
        unregister_code(KC_LALT);
        is_alt_tab_active = false;
      }
  }
  return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

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

static tap dance_state[1];

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


void dance_11_finished(tap_dance_state_t *state, void *user_data);
void dance_11_reset(tap_dance_state_t *state, void *user_data);

void dance_11_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: layer_move(1); break;
        case SINGLE_HOLD: layer_move(0); break;
        case DOUBLE_TAP: layer_move(1); break;
        case DOUBLE_SINGLE_TAP: layer_move(1); break;
    }
}

void dance_11_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_TAP_HOLD(KC_1, LALT(LCTL(KC_1))),
        [DANCE_1] = ACTION_TAP_DANCE_TAP_HOLD(KC_2, LALT(LCTL(KC_2))),
        [DANCE_2] = ACTION_TAP_DANCE_TAP_HOLD(KC_3, LALT(LCTL(KC_3))),
        [DANCE_3] = ACTION_TAP_DANCE_TAP_HOLD(KC_4, LALT(LCTL(KC_4))),
        [DANCE_4] = ACTION_TAP_DANCE_TAP_HOLD(KC_5, LALT(LCTL(KC_5))),
        [DANCE_5] = ACTION_TAP_DANCE_TAP_HOLD(KC_6, LALT(LCTL(KC_6))),
        [DANCE_6] = ACTION_TAP_DANCE_TAP_HOLD(KC_7, LALT(LCTL(KC_7))),
        [DANCE_7] = ACTION_TAP_DANCE_TAP_HOLD(KC_8, LALT(LCTL(KC_8))),
        [DANCE_8] = ACTION_TAP_DANCE_TAP_HOLD(KC_EQUAL, LALT(LCTL(KC_EQUAL))),
        [DANCE_9] = ACTION_TAP_DANCE_TAP_HOLD(KC_SLASH, KC_BSLS),
        [DANCE_10] = ACTION_TAP_DANCE_TAP_HOLD(KC_Z, KC_SYSTEM_SLEEP),
        [DANCE_11] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_11_finished, dance_11_reset),
};
