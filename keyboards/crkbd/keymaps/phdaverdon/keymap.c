/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>
Copyright 2021 Elliot Powell  <@e11i0t23>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "keymap_bepo.h"

enum crkbd_layers {  
  _BEPO,
  _LOWER,
  _RAISE,
  _ADJUST
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
 * |  CW   | À    |   Y  |   X  |   .  |   K  |   ’  |   Q  |   G  |   H  |   F  |  Bksp|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *                  | Shift | LOWER  | Space |  AltG/Entr| RAISE/W| Ç |                 
 * `-----------------------------------------------------------------------------------'
 */

  [_BEPO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_ESC,  BP_B, BP_EACU, BP_P,    BP_O, BP_EGRV,                     BP_DCIR,  BP_V,  BP_D,    BP_L, BP_J,    BP_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_TAB,  GUI_A,       ALT_U,      SFT_I,   CTRL_E,  BP_COMM,                     BP_C,     CTRL_T,  SFT_S,    ALT_R, GUI_N,    BP_M,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     CAPS_WORD, BP_AGRV, BP_Y,     BP_X,    BP_DOT,  BP_K,                     BP_QUOT,  BP_Q,  BP_G,    BP_H, BP_F,    KC_BSPC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LSFT, MO(_LOWER), KC_SPC,    ALTGR_ENTER, RAISE_W, BP_CCED
                                      //`--------------------------'  `--------------------------'
  ),


/* Lower  
 * ,-----------------------------------------------------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   1  |  2   |  3   |   4  |  5   |  6   |   7  |  8   |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  PSCR|  Undo|   Cut| Copy | Paste|Entr  |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *            | Shift | LOWER  | Space |  AltG/Entr| RAISE/W| Ç |
 * `-----------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     BP_HASH,   BP_1, BP_2,  BP_3,   BP_4, BP_5,                                BP_6,   BP_7, BP_8, BP_9,    BP_0,XXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_PRINT_SCREEN,BP_PC_UNDO,BP_PC_CUT,BP_PC_COPY,BP_PC_PASTE,KC_ENTER,                  XXX,  XXX,  XXX,  XXX,  XXX, XXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___, ___, ___,                ___, ___, ___
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
  *           | Shift | LOWER  | Space |  AltG/Entr| RAISE/W| Ç |
  * `-----------------------------------------------------------------------------------'
  */

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     BP_DLR,BP_DQUO,  BP_LDAQ,  BP_RDAQ, BP_LPRN, BP_RPRN,                      BP_AT,   BP_PLUS,BP_MINS,BP_SLSH, BP_ASTR,BP_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     LSFT(BP_EQL),XXX ,RALT(BP_LDAQ),RALT(BP_RDAQ), RALT(BP_LPRN), RALT(BP_RPRN),         KC_INS,KC_HOME,KC_PGUP,XXX, KC_UP,BP_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXX, KC_MPRV,  KC_MNXT , KC_MPLY,   KC_VOLD, KC_VOLU,                      KC_DEL, KC_END, KC_PGDN, KC_LEFT, KC_DOWN, KC_RIGHT, 
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___, ___, ___,                ___, ___, ___
                                      //`--------------------------'  `--------------------------'
  ),

/* Adjust (Lower + Raise)
 */

  [_ADJUST] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___, ___, ___,                ___, ___, ___
                                      //`--------------------------'  `--------------------------'
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
