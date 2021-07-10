/* Copyright 2019 Maciej Matczak
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
#include "more_organic.h"


enum layers {
  _BASE,
  _LOWER,
  _CHARS_LEFT,
  _CHARS_RIGHT,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define NUMPAD MO(_NUMPAD)

// Modfied home row keys
#define MM_A LSFT_T(KC_A)
#define MM_S LCTL_T(KC_S)
#define MM_D LGUI_T(KC_D)
#define MM_F LALT_T(KC_F)

#define MM_J RALT_T(KC_J)
#define MM_K RGUI_T(KC_K)
#define MM_L RCTL_T(KC_L)
#define MM_SCLN RSFT_T(KC_SCLN)

#define MM_R LT(_LOWER, KC_R)
#define MM_I LT(_CHARS_LEFT, KC_I)
#define MM_E LT(_CHARS_RIGHT, KC_E)

#define MM_ESC (LCTL_T(KC_ESC))

// Biggest kudos goes for Smittey:
// https://github.com/Smittey/qmk_firmware/blob/master/keyboards/planck/keymaps/smittey/keymap.c
// https://www.smittey.co.uk/the-planck-key-theory/
// Additional modification prior customizations and additonal row
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* ,-----------------------------------------.  ,-----------------------------------------.
 * | `    |   1  |   2  |   3  |   4  |   5  |  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Ctrl | LGUI | Alt  |      |Enter |Space |  |Lower |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_BASE] = LAYOUT(
    KC_GRAVE,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,        KC_6,   KC_7,    KC_8,    KC_9,    KC_0, KC_MINS,
      KC_TAB,    KC_Q,    KC_W,    MM_E,    MM_R,    KC_T,        KC_Y,   KC_U,    MM_I,    KC_O,    KC_P, KC_BSPC,
      MM_ESC,    MM_A,    MM_S,    MM_D,    MM_F,    KC_G,        KC_H,   MM_J,    MM_K,    MM_L, MM_SCLN, KC_QUOT,
     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,   KC_M, KC_COMM,  KC_DOT, KC_SLSH, MT(MOD_RSFT, KC_ENT),
     XXXXXXX, XXXXXXX, XXXXXXX,   LOWER,  KC_SPC, XXXXXXX,     XXXXXXX, KC_ENT,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  ),


/* ,-----------------------------------------.  ,-----------------------------------------.
 * |      |      |      |      |      |      |  |      |      | PGDN | PGUP |      | PSCR |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      | HOME |      |      | END  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * | Caps | SHFT | CTRL |  GUI |  ALT |      |  |      | LEFT | DOWN |  UP  | RGHT |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      | MUTE | VOL- | VOL+ |      |  |      | |>|| | |<|  | |>|  |      |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |Space |  |      |      |      |      |      | RST  |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_LOWER] = LAYOUT(
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_PGDN, KC_PGUP, XXXXXXX, XXXXXXX, KC_PSCR,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     KC_HOME, XXXXXXX, XXXXXXX,  KC_END, XXXXXXX, _______,
    KC_CAPS, KC_LSFT, KC_LCTL, KC_LGUI, KC_LALT, XXXXXXX,     KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX, _______,
    _______, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX,     KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX, _______,
    _______, _______, _______, _______, _______, _______,     _______, _______,   RESET, _______, _______, _______
  ),


/* ,-----------------------------------------.  ,-----------------------------------------.
 * | F11  |  F1  |  F2  |  F3  |  F4  |  F5  |  |  F6  |  F7  |  F8  |  F9  | F10  | F12  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |   ~  |  !   |  @   |  #   |  $   |  %   |  |  ^   |  &   |  *   |  (   |  )   | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |  /   |  {   |  [   |  |  ]   |  }   |  \   |  -   |  =   |  |   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |      |      |  _   |  +   |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |Space |  |Space |      |      |      |      |      |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  [_CHARS_RIGHT] = LAYOUT(
     KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
    KC_TILD, KC_EXLM,   KC_AT, _______,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, KC_SLSH, KC_LCBR, KC_LBRC,     KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS,  KC_EQL, KC_PIPE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, MT(MOD_LSFT, KC_ENT),
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  ),
  [_CHARS_LEFT] = LAYOUT(
     KC_F11,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F12,
    KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,     KC_CIRC, KC_AMPR, _______, KC_LPRN, KC_RPRN,  KC_DEL,
    _______, XXXXXXX, XXXXXXX, KC_SLSH, KC_LCBR, KC_LBRC,     KC_RBRC, KC_RCBR, KC_BSLS, KC_MINS,  KC_EQL, KC_PIPE,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, MT(MOD_LSFT, KC_ENT),
    _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______
  )


/* ,-----------------------------------------.  ,-----------------------------------------.
 * |      |      |      |      |      |      |  |      |      |   /  |   *  |   -  |      |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   7  |   8  |   9  |   +  | Del  |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   4  |   5  |   6  |   +  |  \   |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |  |      |   1  |   2  |   3  |Enter |Enter |
 * |------+------+------+------+------+------|  |------+------+------+------+------+------|
 * |      | LGUI | Alt  |      |      |Space |  |Space |      |   0  |   .  |Enter |Right |
 * `-----------------------------------------'  `-----------------------------------------'
 */
  // [_CHARS_LEFT] = LAYOUT(
  //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_PSLS, KC_PAST, KC_PMNS, _______,
  //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    KC_7,    KC_8,    KC_9, KC_PPLS,  KC_DEL,
  //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    KC_4,    KC_5,    KC_6, KC_PPLS, KC_BSLS,
  //   _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX,    KC_1,    KC_2,    KC_3, KC_PENT, MT(MOD_RSFT, KC_ENT),
  //   _______, _______, _______, _______, _______, _______,     _______,    KC_0,    KC_0,  KC_DOT, KC_PENT, KC_RGHT
  // ),
};
