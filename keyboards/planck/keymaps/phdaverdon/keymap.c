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

#define LOWER   LT(_LOWER,KC_TAB)
#define RAISE_W   LT(_RAISE, BP_W)
#define ALTGR_ENTER   MT(MOD_RALT,KC_ENTER)
#define SHIFT_TAB   MT(MOD_LSFT,KC_TAB)
#define SHIFT_BSPC   MT(MOD_RSFT,KC_BSPC)
#define GUI_SPACE   MT(MOD_LGUI,KC_SPC)
#define ALT_ESC   MT(MOD_LALT,KC_ESC)
#define CTRL_W   MT(MOD_LCTL,BP_W)


#define BP_PC_UNDO LCTL(BP_Z)
#define BP_PC_CUT LCTL(BP_X)
#define BP_PC_COPY LCTL(BP_C)
#define BP_PC_PASTE LCTL(BP_V)


// Left-hand home row mods
#define GUI_A LGUI_T(BP_A)
#define ALT_U LALT_T(BP_U)
#define SFT_I LSFT_T(BP_I)
#define CTRL_E LCTL_T(BP_E)

// Right-hand home row mods
#define CTRL_T RCTL_T(BP_T)
#define SFT_S RSFT_T(BP_S)
#define ALT_R LALT_T(BP_R)
#define GUI_N RGUI_T(BP_N)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BÉPO
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Tab  |Win/A |Alt/U |Shift/I|Ctrl/E|  ,  |   C  |Ctrl/T|Shift/S|Alt/R|Win/N |   M  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |  Ê   | À    |   Y  |   X  |   .  |   K  |   ’  |   Q  |   G  |   H  |   F  |  Bksp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Shift|LOWER | Space|AltG/Entr|RAISE/W|Ç |      |      |      |                 
 * `-----------------------------------------------------------------------------------'
 */

  [_BEPO] = LAYOUT_planck_grid(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  BP_B, BP_EACU, BP_P,    BP_O, BP_EGRV,                     BP_DCIR,  BP_V,  BP_D,    BP_L, BP_J,    BP_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  GUI_A,       ALT_U,      SFT_I,   CTRL_E,  BP_COMM,                     BP_C,     CTRL_T,  SFT_S,    ALT_R, GUI_N,    BP_M,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     BP_ECIR, BP_AGRV, BP_Y,     BP_X,    BP_DOT,  BP_K,                     BP_QUOT,  BP_Q,  BP_G,    BP_H, BP_F,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         XXX,XXX,XXX,KC_LSFT, MO(_LOWER), KC_SPC,    ALTGR_ENTER, RAISE_W, BP_CCED,XXX,XXX,XXX
                                      //`--------------------------'  `--------------------------'
  ),

/* Lower  
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   1  |  2   |  3   |   4  |  5   |  6   |   7  |  8   |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  Undo|   Cut| Copy | Paste|Entr  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      | Shift|LOWER | Space|AltG/Entr|RAISE/W|Ç |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_planck_grid(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     BP_HASH,   BP_1, BP_2,  BP_3,   BP_4, BP_5,                                BP_6,   BP_7, BP_8, BP_9,    BP_0,XXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXX,BP_PC_UNDO,BP_PC_CUT,BP_PC_COPY,BP_PC_PASTE,KC_ENTER,                  XXX,  XXX,  XXX,  XXX,  XXX, XXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXX,XXX,XXX,___, ___, ___,                ___, ___, ___,XXX,XXX,XXX
                                      //`--------------------------'  `--------------------------'
  ),

 /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |  $   |   "  |  «   |  »   |  (   |   )  |   @  |   +  |   -  |   /  |   *  |   =  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  °   |      |  <   |  >   |  [   |   ]  |  Ins |  Home| Pg Up|      |  Up  |  %   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |Track-|Track+|Play  |Vol-  |Vol+  |  Del |  End | Pg Dn|Left  |Down  |Right |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      | Shift|LOWER | Space|AltG/Entr|RAISE/W|Ç |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */

  [_RAISE] = LAYOUT_planck_grid(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     BP_DLR,BP_DQUO,  BP_LDAQ,  BP_RDAQ, BP_LPRN, BP_RPRN,                      BP_AT,   BP_PLUS,BP_MINS,BP_SLSH, BP_ASTR,BP_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT(BP_EQL),XXX ,RALT(BP_LDAQ),RALT(BP_RDAQ), RALT(BP_LPRN), RALT(BP_RPRN),         KC_INS,KC_HOME,KC_PGUP,XXX, KC_UP,BP_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXX, KC_MPRV,  KC_MNXT , KC_MPLY,   KC_VOLD, KC_VOLU,                      KC_DEL, KC_END, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          XXX,XXX,XXX,___, ___, ___,                ___, ___, ___,XXX,XXX,XXX
                                      //`--------------------------'  `--------------------------'
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
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, BACKLIT,
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