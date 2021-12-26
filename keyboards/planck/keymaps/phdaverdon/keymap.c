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
#include "keymap_bepo.h"

enum planck_layers {  
  _BEPO,
  _LOWER,
  _RAISE,
  _RIGHT,
  _ADJUST
};

enum planck_keycodes {
  BEPO = SAFE_RANGE, 
  BACKLIT
};

/* Shortcodes */

#define ___     KC_TRANSPARENT
#define XXX     KC_NO

#define _MEH    MEH_T(KC_UP)
#define _HYP    ALL_T(BP_W)
#define LOWER   LT(_LOWER,KC_ENTER)
#define RAISE   LT(_RAISE, KC_BSPC)
#define ALTGR   MT(MOD_RALT,KC_LEFT)
#define SHIFTC   MT(MOD_RSFT,BP_CCED)
#define SHIFTW   MT(MOD_LSFT,BP_W)
#define SHIFTTAB   MT(MOD_LSFT,KC_TAB)
#define ALTESC   MT(MOD_LALT,KC_ESC)


#define BP_PC_UNDO LCTL(BP_Z)
#define BP_PC_CUT LCTL(BP_X)
#define BP_PC_COPY LCTL(BP_C)
#define BP_PC_PASTE LCTL(BP_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BÉPO
 * ,-----------------------------------------------------------------------------------.
 * | W  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Ç   |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |   M  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   À  |   Y  |   X  |   .  |   K  |   ’  |   Q  |   G  |   H  |   F  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI |Alt/Esc|Shift/Tab|LOWER/Entr | Space  | RAISE/Bksp|AltG/Left|Down| Up |Right|
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = LAYOUT_planck_grid(
    BP_W,  BP_B,       BP_EACU, BP_P,    BP_O,    BP_EGRV, BP_DCIR,  BP_V,  BP_D,    BP_L, BP_J,    BP_Z,
    BP_CCED,  BP_A,       BP_U,       BP_I,    BP_E,    BP_COMM,   BP_C,     BP_T,  BP_S,    BP_R, BP_N,    BP_M,
    KC_LSFT, BP_AGRV, BP_Y,       BP_X,    BP_DOT,  BP_K,       BP_QUOT,  BP_Q,  BP_G,    BP_H, BP_F,    KC_RSFT,
    KC_LCTL, KC_LGUI, ALTESC,   SHIFTTAB , LOWER,   KC_SPC,     KC_SPC, RAISE, ALTGR, KC_DOWN, KC_UP, KC_RIGHT 
),

/* Lower  
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   1  |  2   |  3   |   4  |  5   |  6   |   7  |  8   |   9  |   0  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Shift||  Undo|   Cut| Copy | Paste|  ,   |  .   |   +  |   -  |   /  |   *  |  Shift    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |Alt/Esc|Shift/Tab|LOWER/Entr| Space  | RAISE/Bksp|AltG/Left|Down| Up |Right|
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    XXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11,   
     BP_HASH,   BP_1, BP_2,  BP_3,   BP_4, BP_5,  BP_6,   BP_7, BP_8, BP_9,    BP_0 ,     KC_F12,
     ___,   BP_PC_UNDO,   BP_PC_CUT,   BP_PC_COPY,   BP_PC_PASTE,   BP_COMM  ,   BP_DOT,   BP_PLUS, BP_MINUS, BP_SLASH,  BP_ASTR,      ___,
    ___, ___, ___, ___, ___,       ___,   ___,     ___,    ___,    ___, ___, ___
),

/* Raise déplacer le pavé del et ajouter les flèches
  * ,-----------------------------------------------------------------------------------.
  * |  $   |   "  |  «   |  »   |  (   |   )  |   @  |   +  |   -  |   /  |   *  |   =  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |  <   |  >   |  [   |   ]  |  Ins |  Home| Pg Up|      |   °  |  %   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift| |      |      |      |      |      |  Del |  End | Pg Dn|Track-|Track+|      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | GUI  |  Alt |Shift |LOWER/Entr| Space  | RAISE/Bksp|Mute teams|Vol-|Vol+|Play |
  * `-----------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_planck_grid(
    BP_DLR,BP_DQUO, BP_LDAQ,       BP_RDAQ,       BP_LPRN,       BP_RPRN,       BP_AT,          BP_PLUS, BP_MINS, BP_SLSH,  BP_ASTR, BP_EQL,
    XXX,    XXX , RALT(BP_LDAQ), RALT(BP_RDAQ), RALT(BP_LPRN), RALT(BP_RPRN),                 KC_INS, KC_HOME, KC_PGUP, XXX,    LSFT(BP_EQL),      BP_PERC,
    ___,     XXX,           XXX,    XXX,  XXX,          XXX,               KC_DEL, KC_END, KC_PGDN,     KC_MPRV,  KC_MNXT , XXX,
    ___,     ___,           ___,           ___,           ___,       ___, ___,     ___,     LCTL(LSFT(BP_M)),   KC_VOLD, KC_VOLU,  KC_MPLY
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|      |      |  BEPO|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |BACKLIT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, RESET,   DEBUG,   RGB_TOG, RGB_MODE_FORWARD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  _______,  BEPO,  _______,  RGB_MODE_KNIGHT,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, BACKLIT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, ___
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case BEPO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEPO);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
      } else {
        unregister_code(KC_RSFT);
      }
      return false;
      break;   
  }
  return true;
}