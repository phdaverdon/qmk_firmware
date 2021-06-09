/*
 * BÉPO layout for Planck keyboards.
 *
 * Author: MARTIN Damien <bepo.plank@martin-damien.fr>
 * License: MIT
 *
 * Note: BÉPO keycode can be retrieved in /quantum/keymap_extras/keymap_bepo.h
 */

#include QMK_KEYBOARD_H
#include "keymap_bepo.h"

extern keymap_config_t keymap_config;

/* Shortcodes */

#define ___     KC_TRANSPARENT
#define XXX     KC_NO
#define _MEH    MEH_T(KC_NO)
#define _HYP    ALL_T(KC_NO)
#define _ORANGE MO(_ORANGE_)
#define _BLUE   MO(_BLUE_)

/* Layers */

#define _BEPO_   0
#define _BLUE_   1
#define _ORANGE_ 2
#define _PURPLE_ 3

/* Layers */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BÉPO
     * ,-----------------------------------------------------------------------------------.
     * | Tab  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |   M  |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * | Shift|   À  |   Y  |   X  |   .  |   K  |   '  |   Q  |   G  |   H  |   F  |   W  |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | MEH  | HYP  | GUI  |ORANGE| Spac | Entr | BLUE | AltG | MEH  | Left | Right|
     * `-----------------------------------------------------------------------------------'
     */
    [_BEPO_] = LAYOUT_planck_grid(
        KC_TAB,  BP_B,       BP_E_ACUTE, BP_P,    BP_O,    BP_E_GRAVE, BP_DCRC,  BP_V,  BP_D,    BP_L, BP_J,    BP_Z,
        KC_ESC,  BP_A,       BP_U,       BP_I,    BP_E,    BP_COMMA,   BP_C,     BP_T,  BP_S,    BP_R, BP_N,    BP_M,
        KC_LSFT, BP_A_GRAVE, BP_Y,       BP_X,    BP_DOT,  BP_K,       BP_APOS,  BP_Q,  BP_G,    BP_H, BP_F,    BP_W,
        KC_LCTL, _MEH,       _HYP,       KC_LGUI, _ORANGE, KC_SPC,     KC_ENTER, _BLUE, KC_RALT, _MEH, KC_LEFT, KC_RIGHT
    ),

    /* BLUE
     * ,-----------------------------------------------------------------------------------.
     * |   "  |  «   |  »   |  (   |   )  |   @  |   +  |   -  |   /  |   *  |   =  |  %   |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * | Esc  |  <   |  >   |  {   |   }  |      |   Ç  |      |   $  |      |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |Shift |      |      |  [   |   ]  |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | MEH  |  HYP | GUI  |ORANGE|   _  | Entr | BLUE | Mute | Vol- | Vol+ | Play |
     * `-----------------------------------------------------------------------------------'
     */
    [_BLUE_] = LAYOUT_planck_grid(
        BP_DQOT, BP_LGIL,       BP_RGIL,       BP_LPRN,       BP_RPRN,       BP_AT,          BP_PLUS, BP_MINUS, BP_SLASH,  BP_ASTR, BP_EQUAL, BP_PERCENT,
        ___,     RALT(BP_LGIL), RALT(BP_RGIL), RALT(BP_Y),    RALT(BP_X),    XXX,            BP_CCED, XXX,      BP_DOLLAR, XXX,     XXX,      XXX,
        ___,     XXX,           XXX,           RALT(BP_LPRN), RALT(BP_RPRN), XXX,            XXX,     XXX,      XXX,       XXX,     XXX,      XXX,
        ___,     ___,           ___,           ___,           _ORANGE,       RALT(KC_SPC),   XXX,     _BLUE,    KC_MUTE,   KC_VOLD, KC_VOLU,  KC_MPLY
    ),

    /* ORANGE
     * ,-----------------------------------------------------------------------------------.
     * |      |      |      |      |      |      |      |  7   |   8  |   9  |      |      |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  4   |   5  |   6  |      |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |  1   |   2  |   3  |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | Ctrl | MEH  |  HYP | GUI  |ORANGE| Spac | Entr | BLUE |   .  |   0  |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_ORANGE_] = LAYOUT_planck_grid(
        XXX, XXX, XXX, XXX, XXX,     XXX, XXX, LSFT(BP_PLUS), LSFT(BP_MINUS), LSFT(BP_SLASH), XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,     XXX, XXX, LSFT(BP_LPRN), LSFT(BP_RPRN),  LSFT(BP_AT),    XXX, XXX,
        XXX, XXX, XXX, XXX, XXX,     XXX, XXX, LSFT(BP_DQOT), LSFT(BP_LGIL),  LSFT(BP_RGIL),  XXX, XXX,
        ___, ___, ___, ___, _ORANGE, ___, ___, _BLUE,         BP_DOT,         LSFT(BP_ASTR),  XXX, XXX
    ),

    /* PURPLE
     * ,-----------------------------------------------------------------------------------.
     * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
     * |------+------+------+------+------+-------------+------+------+------+------+------|
     * |      |      |      |      |  Del |      |      | Left | Down |  Up  |Right |      |
     * |------+------+------+------+------+------|------+------+------+------+------+------|
     * |      |      |      |      |      |      |      |      |      |      |      |      |
     * |------+------+------+------+------+------+------+------+------+------+------+------|
     * | RESET|      |      |      |ORANGE|      |      | BLUE |      |      |      |      |
     * `-----------------------------------------------------------------------------------'
     */
    [_PURPLE_] = LAYOUT_planck_grid(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,   KC_F6, KC_F7, KC_F8,   KC_F9,   KC_F10, KC_F11,   KC_F12,
        XXX,   XXX,   XXX,   XXX,   KC_BSPC, XXX,   XXX,   KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, XXX,
        XXX,   XXX,   XXX,   XXX,   XXX,     XXX,   XXX,   XXX,     XXX,     XXX,    XXX,      XXX,
        RESET, XXX,   XXX,   XXX,   _ORANGE, XXX,   XXX,   _BLUE,   XXX,     XXX,    XXX,      XXX
    )

};

uint32_t layer_state_set_user(uint32_t state) {
    return update_tri_layer_state(state, _BLUE_, _ORANGE_, _PURPLE_);
}
