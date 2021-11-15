/* Copyright 2018 'mechmerlin'
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
  ISOAUML = SAFE_RANGE,
  ISOOUML,
  ISOUUML,
  ISOCOMM,
  ISODOT
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
  KC_TAB,  KC_Q,    KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_CAPS, KC_A,    KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT, KC_PGUP,  \
  KC_LSFT, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT /*MT(KC_RSFT, KC_PGUP)*/, KC_UP,   KC_PGDN, \
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
   _______,_______,  KC_UP,_______,_______,_______,_______,TG(3),KC_PSCR,KC_SLCK,KC_PAUS,  KC_UP,_______,     _______,_______,   \
      _______,KC_LEFT,KC_DOWN,KC_RGHT,_______,_______,_______,_______,KC_HOME,KC_PGUP,KC_LEFT,KC_RGHT,            _______,_______, \
           _______,_______,_______,_______,_______,_______,_______,TG(1), KC_END,KC_PGDN,KC_DOWN,       _______,KC_PGUP,_______, \
    _______,  _______,  _______,                     _______,                     _______,_______,_______,KC_HOME,KC_PGDN, KC_END),

/* Keymap ISO layer */
[3] = LAYOUT_65_ansi(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, KC_Z, _______, _______, _______, _______, ISOUUML, _______, _______, _______, \
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, ISOOUML, ISOAUML,          _______, _______, \
  _______, KC_Y, _______, _______, _______, _______, _______, _______, ISOCOMM, ISODOT, _______, _______, _______, _______, \
  _______, _______, _______,                        _______,                       _______, _______, _______, _______, _______, _______),

};

uint8_t mod_state;\

void send_iso(char* baseChar, char* shiftChar, bool pressed) {
    if (pressed) {
        mod_state = get_mods();

        char* c;
        if (mod_state & MOD_MASK_SHIFT) {
            c = shiftChar;
        } else {
            c = baseChar;
        }

        clear_mods();

        SEND_STRING(SS_DOWN(X_RALT));
        send_string(c);
        SEND_STRING(SS_UP(X_RALT));

        set_mods(mod_state);
    }
}

/* void send_custom(char* base, char* shifted, char* altered, char* altered_shifted) { */
/*     mod_state = get_mods(); */
/*     bool is_shifted = mod_state & MOD_MASK_SHIFT; */
/*     bool is_altered = mod_state & MOD_BIT(KC_RALT); */
/*     if (is_altered) { */
/*         if (is_shifted) { */
/*             send_string(altered_shifted); */
/*         } else { */
/*             send_string(altered); */
/*         } */
/*     } else if (is_shifted) { */
/*         send_string(shifted); */
/*     } else { */
/*         send_string(base); */
/*     } */
/*     set_mods(mod_state); */
/* } */

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();
  switch (keycode) {
  case ISOAUML:
      send_iso("a" /* ä */, "z" /* à */, record -> event.pressed);
      break;
  case ISOOUML:
      send_iso("o" /* ö */, "g" /* é */, record -> event.pressed);
      break;
  case ISOUUML:
      send_iso("u" /* ü */, "f" /* è */, record -> event.pressed);
      break;
  case ISOCOMM:
      /* send_custom(SS_TAP(X_COMM), SS_TAP(X_SCLN), SS_DOWN(X_LSFT) SS_TAP(X_COMM) SS_UP(X_LSFT), KC_NO); */
      if (record -> event.pressed) {
          clear_mods();
          if (mod_state & MOD_MASK_SHIFT) {
              // SHIFT = ;
              SEND_STRING(SS_TAP(X_SCLN));
          } else if (mod_state & MOD_BIT(KC_RALT)) {
              // ALTGR = <
              SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_COMM) SS_UP(X_LSFT));
          } else {
              // DEFAULT = ,
              SEND_STRING(SS_TAP(X_COMM));
          }
          set_mods(mod_state);
      }
      break;
  case ISODOT:
      if (record -> event.pressed) {
          clear_mods();
          if (mod_state & MOD_MASK_SHIFT) {
              // SHIFT = :
              SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_SCLN) SS_UP(X_LSFT));
          } else if (mod_state & MOD_BIT(KC_RALT)) {
              // ALTGR = >
              SEND_STRING(SS_DOWN(X_LSFT) SS_TAP(X_DOT) SS_UP(X_LSFT));
          } else {
              // DEFAULT = .
              SEND_STRING(SS_TAP(X_DOT));
          }
          set_mods(mod_state);
      }
      break;
  }
  return true;
}
