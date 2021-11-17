/* Copyright 2018 'mechmerlin'
 * Copyright 2021 hupf
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
  ISO_AUML = SAFE_RANGE,
  ISO_OUML,
  ISO_UUML,
  ISO_COMM,
  ISO_DOT,
  ISO_2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Home|
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |PgUp|
   * |----------------------------------------------------------------|
   * |Caps   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |PgDn|
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|End |
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt| FN|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[0] = LAYOUT_65_ansi(
  KC_GESC, KC_1,    KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_GRV, \
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Z,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, KC_PGUP,  \
  KC_LSFT, KC_Y,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT /*MT(KC_RSFT, KC_PGUP)*/, KC_UP,   KC_PGDN, \
  KC_LCTL, KC_LGUI, KC_LALT,                KC_SPC,                          KC_RALT, MO(2),   TG(3)/*KC_RCTL*/, KC_LEFT, KC_DOWN, KC_RGHT),

/* Keymap macOS layer */
[1] = LAYOUT_65_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, KC_LALT, KC_LGUI,                     _______,                          _______, _______, _______, _______, _______, _______),

/* [1] = LAYOUT_65_ansi( */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, \ */
/*   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \ */
/*   _______, _______, _______,                        _______,                       _______, _______, _______, _______, _______, _______), */

  /* Keymap Fn Layer
   * ,----------------------------------------------------------------.
   * |~ `|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Ins |
   * |----------------------------------------------------------------|
   * |     |   |Up |   |   |   |   |   |PSc|SLk|Pau|Up |   |     |    |
   * |----------------------------------------------------------------|
   * |      |Lef|Dow|Rig|   |   |   |   |Hom|PUp|Lef|Rig|        |    |
   * |----------------------------------------------------------------|
   * |        |   |   |   |   |   |   |   |End|PDn|Dow|      |PUp|    |
   * |----------------------------------------------------------------|
   * |    |    |    |                       |   |   |    |Hom|PDn|End |
   * `----------------------------------------------------------------'
   */
[2] = LAYOUT_65_ansi(
   KC_GRV,  KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9, KC_F10, KC_F11, KC_F12,          KC_DEL,KC_INS, \
   _______,_______,  KC_UP,_______,_______,_______,_______,_______,KC_PSCR,KC_SLCK,KC_PAUS,  KC_UP,_______,     _______,_______,   \
      _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,KC_HOME,KC_PGUP,KC_LEFT,KC_RGHT,            _______,KC_HOME, \
   _______,_______,_______,_______,_______,_______,TG(4),TG(1), KC_END,KC_PGDN,KC_DOWN,       _______,KC_PGUP,KC_END, \
    _______,  _______,  _______,                     _______,                     _______,_______,_______,KC_HOME,KC_PGDN, KC_END),

/* Keymap ISO layer */
[3] = LAYOUT_65_ansi(
  _______, _______, ISO_2, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_Z, _______, _______, _______, _______, ISO_UUML, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ISO_OUML, ISO_AUML,          _______, _______, \
  _______, KC_Y, _______, _______, _______, _______, _______, _______, ISO_COMM, ISO_DOT, _______, _______, _______, _______, \
  _______, _______, _______,                        _______,                       _______, _______, _______, _______, _______, _______),

/* Numpad layer */
[4] = LAYOUT_65_ansi(
  _______, _______, _______, _______, _______, _______, _______, KC_KP_7, KC_KP_8, KC_KP_9, KC_KP_PLUS, KC_KP_MINUS, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_KP_4, KC_KP_5, KC_KP_6, KC_KP_ASTERISK, KC_KP_SLASH, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_KP_1, KC_KP_2, KC_KP_3, KC_KP_EQUAL, _______,          _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, KC_KP_0, KC_KP_0, KC_KP_DOT, KC_KP_ENTER, _______, _______, _______, \
  _______, _______, _______,                        _______,                       _______, _______, _______, _______, _______, _______),

};

void send_custom(keyrecord_t *record, char* base, char* shifted, char* altered, char* altered_shifted) {
    if (record->event.pressed) {
        uint8_t mod_state = get_mods();
        bool shift = mod_state & MOD_MASK_SHIFT;
        bool alt = mod_state & MOD_BIT(KC_RALT);

        clear_mods();
        if (alt) {
            if (shift) {
                send_string(altered_shifted);
            } else {
                send_string(altered);
            }
        } else if (shift) {
            send_string(shifted);
        } else {
            send_string(base);
        }
        set_mods(mod_state);
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  case ISO_AUML:
      send_custom(
        record,
        SS_DOWN(X_RALT) SS_TAP(X_A) SS_UP(X_RALT), // ä
        SS_DOWN(X_RALT) SS_TAP(X_Z) SS_UP(X_RALT), // à
        SS_TAP(X_QUOT), // '
        SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT) // "
      );
      break;
  case ISO_OUML:
      send_custom(
        record,
        SS_DOWN(X_RALT) SS_TAP(X_O) SS_UP(X_RALT), // ö
        SS_DOWN(X_RALT) SS_TAP(X_G) SS_UP(X_RALT), // é
        SS_TAP(X_SCLN), // ;
        SS_DOWN(X_LSFT) SS_TAP(X_SCLN) SS_UP(X_LSFT) // :
      );
      break;
  case ISO_UUML:
      /* send_iso("u" /\* ü *\/, "f" /\* è *\/, record -> event.pressed); */
      send_custom(
        record,
        SS_DOWN(X_RALT) SS_TAP(X_U) SS_UP(X_RALT), // ü
        SS_DOWN(X_RALT) SS_TAP(X_F) SS_UP(X_RALT), // è
        KC_NO,
        KC_NO
      );
      break;
  case ISO_COMM:
      send_custom(
        record,
        SS_TAP(X_COMM), // ,
        SS_TAP(X_SCLN), // ;
        SS_DOWN(X_LSFT) SS_TAP(X_COMM) SS_UP(X_LSFT), // <
        KC_NO
      );
      break;
  case ISO_DOT:
      send_custom(
        record,
        SS_TAP(X_DOT), // .
        SS_DOWN(X_LSFT) SS_TAP(X_SCLN) SS_UP(X_LSFT), // :
        SS_DOWN(X_LSFT) SS_TAP(X_DOT) SS_UP(X_LSFT), // >
        KC_NO
      );
      break;
  case ISO_2:
      send_custom(
        record,
        SS_TAP(X_2), // 2
        SS_DOWN(X_LSFT) SS_TAP(X_QUOT) SS_UP(X_LSFT), // "
        SS_DOWN(X_LSFT) SS_TAP(X_2) SS_UP(X_LSFT), // @
        SS_TAP(X_QUOT) // '
      );
      break;
  }
  return true;
}
