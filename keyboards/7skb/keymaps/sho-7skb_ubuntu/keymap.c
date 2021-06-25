#include QMK_KEYBOARD_H


#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _L0 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _INFO 5

enum custom_keycodes {
  MC_MAIL1 = SAFE_RANGE,
  MC_MAIL2,
  MC_MAIL3,
  MC_MAIL4,
  MC_SITE1,
  MC_SITE2,
  MC_SITE3,
  MC_SITE4,
  MC_HOME,
  MC_END,
  MC_AL,
  MC_WORD,
  MC_LINE,
  MC_YANK,
  MC_PASTE,
  MC_UNDO,
  MC_REDO,
  MC_DOWN,
  MC_UP,
  MC_RIGHT,
  MC_LEFT,
  MC_CNTR,
  MC_BTTM,
  MC_CLNG,
};

#define KC_L1 MO(_L1)
#define KC_L2 MO(_L2)
#define KC_L3 MO(_L3)
#define KC_INFO MO(_INFO)
#define ESCL2 LT(_L2, KC_ESC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_L0] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSLS, _______, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT, KC_INFO,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               KC_LALT, KC_LGUI,   KC_L1,  KC_SPC,               KC_ENT,  ESCL2,          KC_L3, KC_RALT 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L1] = LAYOUT(
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      _______, _______,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
       KC_ESC, KC_EXLM,   KC_AT, KC_HASH, KC_PERC, KC_AMPR,     KC_ASTR, KC_CIRC, KC_UNDS,  KC_EQL,  KC_DLR,  KC_GRV, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
     KC_LCTRL, KC_HOME,KC_PGDOWN,KC_PGUP,  KC_END, KC_BSPC,     KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, KC_SCLN, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      KC_LSFT, _______, _______, _______, _______, _______,     KC_PLUS, KC_MINS, KC_COMM,  KC_DOT, KC_SLSH, _______, _______,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               _______, KC_LGUI,   KC_L1,  KC_SPC,               KC_ENT,   ESCL2,      KC_RALT, _______ 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L2] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,     KC_BSPC,    KC_7,    KC_8,    KC_9, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, KC_LPRN, KC_RPRN, XXXXXXX, XXXXXXX,        KC_0,    KC_4,    KC_5,    KC_6, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_DOT,    KC_1,    KC_2,    KC_3, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, KC_LGUI,   KC_L1,  KC_SPC,               KC_ENT,   ESCL2,       KC_RALT, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_L3] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, MC_WORD, MC_CNTR, MC_REDO, XXXXXXX,     MC_YANK, MC_UNDO, MC_LINE,   MC_AL,MC_PASTE, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_LEFT, MC_DOWN,   MC_UP,MC_RIGHT, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, KC_LGUI,   KC_L1,  KC_SPC,               KC_ENT,   ESCL2,       KC_RALT, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  ),

  [_INFO] = LAYOUT( /* Base */
  //,-----------------------------------------------------|   |--------------------------------------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,MC_SITE1,MC_SITE2,MC_SITE3,MC_SITE4, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX,MC_MAIL1,MC_MAIL2,MC_MAIL3,MC_MAIL4, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|   |--------+--------+--------+--------+--------+--------+--------|
               XXXXXXX, KC_LGUI,   KC_L1,  KC_SPC,               KC_ENT,   ESCL2,       KC_RALT, XXXXXXX 
          //`---------------------------------------------|   |--------------------------------------------'
  )
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case MC_MAIL1:
        if (record->event.pressed) {
            SEND_STRING("shoshoinoue@icloud.com");
        } else {
        }
        break;

    case MC_MAIL2:
        if (record->event.pressed) {
            SEND_STRING("shoshoinoue@gmail.com");
        } else {
        }
        break;

    case MC_MAIL3:
        if (record->event.pressed) {
            SEND_STRING("s-inoue-tgz@eagle.sophia.ac.jp");
        } else {
        }
        break;

    case MC_MAIL4:
        if (record->event.pressed) {
            SEND_STRING("sho@connected-robotics.com");
        } else {
        }
        break;

    case MC_SITE1:
        if (record->event.pressed) {
            SEND_STRING("tibakenn");
        } else {
        }
        break;

    case MC_SITE2:
        if (record->event.pressed) {
            SEND_STRING("hunabasisi");
        } else {
        }
        break;

    case MC_SITE3:
        if (record->event.pressed) {
            SEND_STRING("miyamoto");
        } else {
        }
        break;

    case MC_SITE4:
        if (record->event.pressed) {
            SEND_STRING("3-3-3-1");
        } else {
        }
        break;

    case MC_HOME: // HOME for Mac
      if (record->event.pressed) {
  		register_code(KC_LGUI);
		register_code(KC_LEFT);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_LEFT);
      }
      break;

    case MC_END: // END for Mac
      if (record->event.pressed) {
  		register_code(KC_LGUI);
		register_code(KC_RIGHT);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_RIGHT);
      }
      break;

    case MC_AL: // Add Line
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_RIGHT);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_RIGHT);
		tap_code(KC_ENT);
      }
      break;

    case MC_WORD: // Blanket one word
      if (record->event.pressed) {
		register_code(KC_LALT);
		register_code(KC_LEFT);
      } else {
		unregister_code(KC_LALT);
		unregister_code(KC_LEFT);
      }

      if (record->event.pressed) {
		register_code(KC_LALT);
		register_code(KC_LSFT);
		register_code(KC_RIGHT);
      } else {
		unregister_code(KC_LALT);
		unregister_code(KC_LSFT);
		unregister_code(KC_RIGHT);
      }
      break;

    case MC_LINE: // Blanket whole line
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_LEFT);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_LEFT);
      }

      if (record->event.pressed) {
		register_code(KC_LSFT);
		register_code(KC_LGUI);
		register_code(KC_RIGHT);
      } else {
		unregister_code(KC_LSFT);
		unregister_code(KC_LGUI);
		unregister_code(KC_RIGHT);
      }
      break;

    case MC_YANK: // yank
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_C);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_C);
      }
      break;

    case MC_PASTE: // paste
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_V);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_V);
      }
      break;

    case MC_UNDO: // undo
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_Z);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_Z);
      }
      break;

    case MC_REDO: // redo
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_LSFT);
		register_code(KC_Z);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_LSFT);
		unregister_code(KC_Z);
      }
      break;

    case MC_CNTR: // set a cursor to the center
      if (record->event.pressed) {
		register_code(KC_LCTL);
		register_code(KC_L);
      } else {
		unregister_code(KC_LCTL);
		unregister_code(KC_L);
      }
      break;

    case MC_BTTM: // move to the bottom.
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_DOWN);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_DOWN);
      }
      break;

    case MC_CLNG: // move to the ceiling.
      if (record->event.pressed) {
		register_code(KC_LGUI);
		register_code(KC_UP);
      } else {
		unregister_code(KC_LGUI);
		unregister_code(KC_UP);
      }
      break;

    case MC_LEFT: // LEFT by word
      if (record->event.pressed) {
		register_code(KC_LALT);
		register_code(KC_LEFT);
      } else {
		unregister_code(KC_LALT);
		unregister_code(KC_LEFT);
      }

      break;

    case MC_RIGHT: // RIGHT by word
      if (record->event.pressed) {
		register_code(KC_LALT);
		register_code(KC_RIGHT);
      } else {
		unregister_code(KC_LALT);
		unregister_code(KC_RIGHT);
      }

      break;

    case MC_DOWN: // DOWN by 5 lines
      if (record->event.pressed) {
		tap_code(KC_DOWN);
		tap_code(KC_DOWN);
		tap_code(KC_DOWN);
		tap_code(KC_DOWN);
		tap_code(KC_DOWN);
	}
      break;

    case MC_UP: // UP by 5 lines
      if (record->event.pressed) {
		tap_code(KC_UP);
		tap_code(KC_UP);
		tap_code(KC_UP);
		tap_code(KC_UP);
		tap_code(KC_UP);
	}
      break;

    }
    return true;
};


