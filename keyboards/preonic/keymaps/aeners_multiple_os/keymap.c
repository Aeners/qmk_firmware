/* Copyright 2015-2017 Jack Humbert
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
#include "muse.h"

#define M_SLEEP M(0)

// Suffix _W is for windows profile
enum preonic_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _QWERTY_W,
  _LOWER_W,
  _RAISE_W,
  _ADJUST
};

enum preonic_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  QWERTY_W,
  LOWER_W,
  RAISE_W,
  BACKLIT
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty for Windows
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|  F6  | Alt  | End  |LowerW|    Space    |RaiseW| Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY_W] = LAYOUT_preonic_grid( \
   KC_GRV,   KC_1,     KC_2,     KC_3,   KC_4,    KC_5,    KC_6,   KC_7,     KC_8,     KC_9,     KC_0,  KC_BSPC, \
   KC_TAB,   KC_Q,     KC_W,     KC_E,   KC_R,    KC_T,    KC_Y,   KC_U,     KC_I,     KC_O,     KC_P,   KC_DEL,  \
   KC_ESC,   KC_A,     KC_S,     KC_D,   KC_F,    KC_G,    KC_H,   KC_J,     KC_K,     KC_L,  KC_SCLN,   KC_ENT, \
  KC_LSFT,   KC_Z,     KC_X,     KC_C,   KC_V,    KC_B,    KC_N,   KC_M,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_QUOT,  \
  KC_LCTL,  KC_F6,  KC_LALT,   KC_END,LOWER_W,  KC_SPC,  KC_SPC,RAISE_W,  KC_LEFT,  KC_DOWN,    KC_UP,  KC_RGHT  \
),

/* Raise for Windows
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |  #   |   ^  |   *  |  -_  |  =+  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |  4   |   5  |   6  |      |      |  &   |  \|  |  Up  |  [{  |  ]}  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ~   | Left | Down |Right |  ;:  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |  |   |   $  |  ,<  |  .>  |  /?  |  '"  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl|  F6  | Alt  | End  |      |      |      |      | Prev | Play | Next | Mute |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE_W] = LAYOUT_preonic_grid( \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_HASH,  KC_CIRC,  KC_ASTR,  KC_MINS,   KC_EQL,  KC_BSPC,  \
  _______,    KC_P4,    KC_P5,    KC_P6,  _______,  _______,  KC_AMPR,  KC_BSLS,    KC_UP,  KC_LBRC,  KC_RBRC,   KC_DEL,  \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_TILD,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_SCLN,   KC_ENT,  \
  KC_LSFT,  _______,  _______,  _______,  _______,  _______,  KC_PIPE,   KC_DLR,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_QUOT,  \
  KC_LCTL,    KC_F6,  KC_LALT,   KC_END,  _______,   _______,  _______,  _______,  KC_MRWD,  KC_MPLY,  KC_MFFD,  KC_MUTE   \
),

/* Lower for Windows
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |      |  /   |  *   |  -   |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  | F10  |  7   |  8   |  9   |  +   | mlPan| mrPan| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | F11  |  4   |  5   |  6   |  ,   |      |      | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      | F12  |  1   |  2   |  3   |  =   |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      0      |  .   | Enter| Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER_W] = LAYOUT_preonic_grid( \
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,  _______,  KC_PSLS,  KC_PAST,  KC_PMNS,  _______,  _______,  KC_BSPC,  \
  _______,    KC_F7,    KC_F8,    KC_F9,   KC_F10,    KC_P7,    KC_P8,    KC_P9,  KC_PPLS,     M(3),     M(2),   KC_DEL,  \
  _______,  _______,  _______,  _______,   KC_F11,    KC_P4,    KC_P5,    KC_P6,  KC_PCMM,  _______,  _______,   KC_ENT,  \
  _______,  _______,  _______,  _______,   KC_F12,    KC_P1,    KC_P2,    KC_P3,  KC_PEQL,  _______,    KC_UP,  _______,  \
  _______,  _______,  _______,  _______,  _______,    KC_P0,    KC_P0,  KC_PDOT,  KC_PENT,  KC_LEFT,  KC_DOWN,  KC_RGHT   \
),


/* Qwerty for OSX
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | LCtrl| RCtrl| Alt  | LGUI |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_preonic_grid( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_DEL,  \
  KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_QUOT,  \
  KC_LCTL, KC_RCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
),

/* Raise for OSX
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | PWR  |   ^  |   *  |  -_  |  =+  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  | F10  | F11  | F12  |  &   |  \|  |  Up  |  [{  |  ]}  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |  ~   | Left | Down |Right |  ;:  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |  |   |   $  |  ,<  |  .>  |  /?  |  '"  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RCtrl| Ctrl | Alt  | GUI  |      |      |      |      | F14  | F15  | F16  | F17  |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_preonic_grid( \
    KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5, KC_POWER,  KC_HASH,  KC_CIRC,  KC_ASTR,  KC_MINS,   KC_EQL,  KC_BSPC,  \
    KC_F7,    KC_F8,    KC_F9,   KC_F10,   KC_F11,   KC_F12,  KC_AMPR,  KC_BSLS,    KC_UP,  KC_LBRC,  KC_RBRC,   KC_DEL,  \
  _______,  _______,  _______,  _______,  _______,  _______,  KC_TILD,  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_SCLN,   KC_ENT,  \
  KC_LSFT,  _______,  _______,  _______,  _______,  _______,  KC_PIPE,   KC_DLR,  KC_COMM,   KC_DOT,  KC_SLSH,  KC_QUOT,  \
  KC_LCTL,  KC_RCTL,  KC_LALT,  KC_LGUI,  _______,  _______,  _______,  _______,   KC_F14,   KC_F15,   KC_F16,   KC_F17  \
),

/* Lower for OSX
 * ,-----------------------------------------------------------------------------------.
 * | F13  |      |      |      |      | F18  |  /   |  *   |  -   |      |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Prev | Play | Next |      |      |  7   |  8   |  9   |  +   | mlPan| mrPan| Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Vol- | Mute | Vol+ | mTerm|CtrlF1|  4   |  5   |  6   |  ,   |      |      | Enter|
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Bri- | Bri+ |      |      |      |  1   |  2   |  3   |  =   |      |  Up  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Sleep|      |      |      |      |      0      |  .   | Enter| Left | Down | Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_preonic_grid( \
   KC_F13,  _______,  _______,  _______,  _______,   KC_F18,  KC_PSLS,  KC_PAST,  KC_PMNS,  _______,  _______,  KC_BSPC,  \
  KC_MRWD,  KC_MPLY,  KC_MFFD,  _______,  _______,    KC_P7,    KC_P8,    KC_P9,  KC_PPLS,     M(3),     M(2),   KC_DEL,  \
  KC_VOLD,  KC_MUTE,  KC_VOLU,     M(1),     M(0),    KC_P4,    KC_P5,    KC_P6,  KC_PCMM,  _______,  _______,   KC_ENT,  \
  KC_BRID,  KC_BRIU,  _______,  _______,  _______,    KC_P1,    KC_P2,    KC_P3,  KC_PEQL,  _______,    KC_UP,  _______,  \
     M(0),  _______,  _______,  _______,  _______,    KC_P0,    KC_P0,  KC_PDOT,  KC_PENT,  KC_LEFT,  KC_DOWN,  KC_RGHT   \
),


/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |Aud on|AudOff|AGnorm|AGswap|Qw_OSX|Qw_Win|      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|MusOff|MidiOn|MidOff|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_preonic_grid( \
  KC_F1  ,  KC_F2  ,  KC_F3  ,  KC_F4  ,  KC_F5  ,  KC_F6  ,  KC_F7  ,  KC_F8  ,  KC_F9  ,  KC_F10 ,  KC_F11 ,  KC_F12 , \
  _______,  RESET  ,  DEBUG  ,  _______,  _______,  _______,  _______,  TERM_ON, TERM_OFF,  _______,  _______,  KC_DEL , \
  _______,  _______,  MU_MOD ,  AU_ON  ,  AU_OFF ,  QWERTY , QWERTY_W,  AG_NORM,  AG_SWAP,  _______,  _______,  _______, \
  _______,  MUV_DE ,  MUV_IN ,  MU_ON  ,  MU_OFF ,  MI_ON  ,  MI_OFF ,  _______,  _______,  _______,  _______,  _______, \
  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______  \
)


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
        case QWERTY:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
          }
          return false;
          break;
        case QWERTY_W:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY_W);
          }
          return false;
          break;
        case LOWER:
          if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case LOWER_W:
          if (record->event.pressed) {
            layer_on(_LOWER_W);
            update_tri_layer(_LOWER_W, _RAISE_W, _ADJUST);
          } else {
            layer_off(_LOWER_W);
            update_tri_layer(_LOWER_W, _RAISE_W, _ADJUST);
          }
          return false;
          break;
        case RAISE:
          if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          } else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
          }
          return false;
          break;
        case RAISE_W:
          if (record->event.pressed) {
            layer_on(_RAISE_W);
            update_tri_layer(_LOWER_W, _RAISE_W, _ADJUST);
          } else {
            layer_off(_RAISE_W);
            update_tri_layer(_LOWER_W, _RAISE_W, _ADJUST);
          }
          return false;
          break;
        case BACKLIT:
          if (record->event.pressed) {
            register_code(KC_RSFT);
            #ifdef BACKLIGHT_ENABLE
              backlight_step();
            #endif
            #ifdef __AVR__
            PORTE &= ~(1<<6);
            #endif
          } else {
            unregister_code(KC_RSFT);
            #ifdef __AVR__
            PORTE |= (1<<6);
            #endif
          }
          return false;
          break;
      }
    return true;
};

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

void encoder_update(bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      register_code(KC_PGDN);
      unregister_code(KC_PGDN);
    } else {
      register_code(KC_PGUP);
      unregister_code(KC_PGUP);
    }
  }
}

void dip_update(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      break;
    case 1:
      if (active) {
        muse_mode = true;
      } else {
        muse_mode = false;
        #ifdef AUDIO_ENABLE
          stop_all_notes();
        #endif
      }
   }
}

void matrix_scan_user(void) {
  #ifdef AUDIO_ENABLE
    if (muse_mode) {
      if (muse_counter == 0) {
        uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
        if (muse_note != last_muse_note) {
          stop_note(compute_freq_for_midi_note(last_muse_note));
          play_note(compute_freq_for_midi_note(muse_note), 0xF);
          last_muse_note = muse_note;
        }
      }
      muse_counter = (muse_counter + 1) % muse_tempo;
    }
  #endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  if (record->event.pressed) {
    switch (id)
    {
      case 0:
        return MACRO(D(LCTL), T(H), END);
      case 1:
        return MACRO(D(LALT), T(SPACE), END);
      case 2:
        return MACRO(D(LCTL), T(RIGHT), END);
      case 3:
        return MACRO(D(LCTL), T(LEFT), END);
    }
  }
  return MACRO_NONE;
}
