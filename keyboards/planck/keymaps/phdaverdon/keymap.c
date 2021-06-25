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
#define _HYP    ALL_T(KC_NO)
#define LOWER   LT(_LOWER,KC_DOWN)
#define RAISE   LT(_RAISE, KC_LEFT)
#define ALTGR   MT(MOD_RALT,KC_RIGHT)
#define RIGESC  LT(_RIGHT, KC_ESC)
#define SHIFTENTER   MT(MOD_RSFT,KC_ENTER)


#define BP_PC_UNDO LCTL(BP_Z)
#define BP_PC_CUT LCTL(BP_X)
#define BP_PC_COPY LCTL(BP_C)
#define BP_PC_PASTE LCTL(BP_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* BÉPO
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |RigEsc|   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |   M  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   À  |   Y  |   X  |   .  |   K  |   ’  |   Q  |   G  |   H  |   F  | Shift/Entr |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |MEH/UP|LOWER/Down|Spac    |RAISE/Left|AltG/Right|Bksp|W|  Ç  |
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = LAYOUT_planck_grid(
    KC_TAB,  BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE, BP_DCRC,  BP_V,  BP_D,    BP_L, BP_J,    BP_Z,
    RIGESC,  BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,   BP_C,     BP_T,  BP_S,    BP_R, BP_N,    BP_M,
    KC_LSFT, BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,       BP_APOS,  BP_Q,  BP_G,    BP_H, BP_F,    SHIFTENTER,
    KC_LCTL, KC_LGUI, KC_LALT,   _MEH    , LOWER,   KC_SPC,     KC_SPC, RAISE, ALTGR, KC_BSPC, BP_W, BP_CCED
),

/* RIGHT
     * ,-----------------------------------------------------------------------------------.
     * |  Tab |      |      |      |      |      |  7   |   8  |   9  |  Ins |  Home| Pg Up|
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |RigEsc|      |      |      |      |      |  4   |   5  |   6  |  Del |  End | Pg Dn|
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|      |      |      |      |      |  1   |   2  |   3  |      |  Up  | Shift/Entr |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | GUI  |  Alt |MEH/UP|LOWER/Down|Spac     |  0   |   .  |  Left|  Down| Right|
     * `-----------------------------------------------------------------------------------'     
     */
    [_RIGHT] = LAYOUT_planck_grid(
        ___, XXX, XXX, XXX, XXX, XXX, LSFT(BP_PLUS), LSFT(BP_MINUS), LSFT(BP_SLASH), KC_INS, KC_HOME, KC_PGUP,
        ___, XXX, XXX, XXX, XXX, XXX, LSFT(BP_LPRN), LSFT(BP_RPRN),  LSFT(BP_AT),    KC_DEL, KC_END, KC_PGDN,
        ___, XXX, XXX, XXX, XXX, XXX, LSFT(BP_DQOT), LSFT(BP_LGIL),  LSFT(BP_RGIL),  XXX, KC_UP, ___,
        ___, ___, ___, ___, ___, ___, ___,LSFT(BP_ASTR), BP_DOT       ,           KC_LEFT,  KC_DOWN, KC_RIGHT
    ),

/* Lower  
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RigEsc|   1  |  2   |  3   |   4  |  5   |  6   |   7  |  8   |   9  |   0  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|  Undo|   Cut| Copy | Paste|  .   |  ,   |   +  |   -  |   /  |   *  |  Shift/Entr    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |  Alt |MEH/UP|LOWER/Down|Spac     |RAISE/Left|AltG/Right|Vol-| Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    ___, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11,   
     ___,   LSFT(BP_DQOT), LSFT(BP_LGIL),  LSFT(BP_RGIL),   LSFT(BP_LPRN), LSFT(BP_RPRN),  LSFT(BP_AT),   LSFT(BP_PLUS), LSFT(BP_MINUS), LSFT(BP_SLASH),    LSFT(BP_ASTR) ,     KC_F12,
     ___,   BP_PC_UNDO,   BP_PC_CUT,   BP_PC_COPY,   BP_PC_PASTE,     BP_DOT,   BP_COMMA,   BP_PLUS, BP_MINUS, BP_SLASH,  BP_ASTR,      ___,
    ___, ___, ___, ___, ___,       ___,   ___,     ___,    ___,    KC_VOLD, KC_VOLU, KC_MPLY
),

/* Raise
  * ,-----------------------------------------------------------------------------------.
  * |  #   |   "  |  «   |  »   |  (   |   )  |   @  |   +  |   -  |   /  |   *  |   =  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | Esc  |  $   |  <   |  >   |  [   |   ]  |      |      |      |      |      |  %   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |Shift |      |  {   |   }  |      |      |      |      |      |      |      |  Shift/Entr    |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * | Ctrl | GUI  |  Alt |MEH/UP|LOWER/Down|Spac     |RAISE/Left|AltG/Right|Vol-|Vol+|Play |
  * `-----------------------------------------------------------------------------------'
  */
[_RAISE] = LAYOUT_planck_grid(
    BP_HASH,BP_DQOT, BP_LGIL,       BP_RGIL,       BP_LPRN,       BP_RPRN,       BP_AT,          BP_PLUS, BP_MINUS, BP_SLASH,  BP_ASTR, BP_EQUAL,
    ___,     BP_DOLLAR, RALT(BP_LGIL), RALT(BP_RGIL), RALT(BP_LPRN), RALT(BP_RPRN),                XXX, XXX,     XXX,  XXX,     XXX,      BP_PERCENT,
    ___,     XXX,           RALT(BP_Y),    RALT(BP_X),  XXX,          XXX,            XXX,     XXX,      XXX,       XXX,     XXX,      ___,
    ___,     ___,           ___,           ___,           ___,       ___,   ___,     ___,    ___,   KC_VOLD, KC_VOLU,  KC_MPLY
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