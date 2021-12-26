/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

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

#define _MEH    MEH_T(KC_UP)
#define _HYP    ALL_T(BP_W)
#define LOWER   LT(_LOWER,KC_TAB)
#define RAISE   LT(_RAISE, KC_BSPC)
#define ALTGR   MT(MOD_RALT,KC_ENTER)
#define SHIFTC   MT(MOD_RSFT,BP_CCED)
#define SHIFTW   MT(MOD_LSFT,BP_W)
#define SHIFTTAB   MT(MOD_LSFT,KC_TAB)
#define CTRLSPACE   MT(MOD_LCTL,KC_SPC)
#define ALTESC   MT(MOD_LALT,KC_ESC)


#define BP_PC_UNDO LCTL(BP_Z)
#define BP_PC_CUT LCTL(BP_X)
#define BP_PC_COPY LCTL(BP_C)
#define BP_PC_PASTE LCTL(BP_V)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    

/* BÉPO
 * ,-----------------------------------------------------------------------------------.
 * | Ç  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | W   |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |   M  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   À  |   Y  |   X  |   .  |   K  |   ’  |   Q  |   G  |   H  |   F  | Shift|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *            | GUI | LOWER/Tab  |Ctrl/Space |  AltG/Entr| RAISE/Bksp|Alt/Esc|                 
 * `-----------------------------------------------------------------------------------'
 */

  [_BEPO] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     BP_CCED,  BP_B, BP_EACU, BP_P,    BP_O, BP_EGRV,                     BP_DCIR,  BP_V,  BP_D,    BP_L, BP_J,    BP_Z,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     BP_W,  BP_A,       BP_U,      BP_I,   BP_E,  BP_COMM,                     BP_C,     BP_T,  BP_S,    BP_R, BP_N,    BP_M,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_LSFT, BP_AGRV, BP_Y,     BP_X,    BP_DOT,  BP_K,                     BP_QUOT,  BP_Q,  BP_G,    BP_H, BP_F,    KC_RSFT,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                         KC_LGUI, LOWER, CTRLSPACE,    ALTGR, RAISE, ALTESC
                                      //`--------------------------'  `--------------------------'
  ),


/* Lower  
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   #  |   1  |  2   |  3   |   4  |  5   |  6   |   7  |  8   |   9  |   0  |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  Shift|  Undo|   Cut| Copy | Paste|  ,   |  .   | Left|Down| Up |Right| Shift    |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 *            | GUI | LOWER/Tab  |Ctrl/Space |  AltG/Entr| RAISE/Bksp|Alt/Esc|
 * `-----------------------------------------------------------------------------------'
 */

  [_LOWER] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     XXX, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                                    KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11, 
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     BP_HASH,   BP_1, BP_2,  BP_3,   BP_4, BP_5,                                BP_6,   BP_7, BP_8, BP_9,    BP_0,KC_F12,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ___,BP_PC_UNDO,BP_PC_CUT,BP_PC_COPY,BP_PC_PASTE,BP_COMM,                  BP_DOT, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT , ___,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          ___, ___, ___,                ___, ___, ___
                                      //`--------------------------'  `--------------------------'
  ),

 /* Raise
  * ,-----------------------------------------------------------------------------------.
  * |  $   |   "  |  «   |  »   |  (   |   )  |   @  |   +  |   -  |   /  |   *  |   =  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |  <   |  >   |  [   |   ]  |  Ins |  Home| Pg Up|      |   °  |  %   |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * | Shift|      |      |Mute teams|Vol-|Vol+|  Del |  End | Pg Dn|Track-|Track+| Play |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  *           | GUI | LOWER/Tab  |Ctrl/Space |  AltG/Entr| RAISE/Bksp|Alt/Esc|
  * `-----------------------------------------------------------------------------------'
  */

  [_RAISE] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
     BP_DLR,BP_DQUO,  BP_LDAQ,  BP_RDAQ, BP_LPRN, BP_RPRN,                      BP_AT,   BP_PLUS,BP_MINS,BP_SLSH, BP_ASTR,BP_EQL,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     XXX,XXX ,RALT(BP_LDAQ),RALT(BP_RDAQ), RALT(BP_LPRN), RALT(BP_RPRN),         KC_INS,KC_HOME,KC_PGUP,XXX,LSFT(BP_EQL),BP_PERC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     ___, XXX, XXX,   LCTL(LSFT(BP_M)),   KC_VOLD, KC_VOLU,                      KC_DEL, KC_END, KC_PGDN, KC_MPRV,  KC_MNXT , KC_MPLY,
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

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}
*/

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
