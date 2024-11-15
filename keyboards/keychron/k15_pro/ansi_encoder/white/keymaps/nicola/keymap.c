/* Copyright 2023 @ Keychron (https://www.keychron.com)
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

// NICOLA親指シフト
#include "nicola.h"
NGKEYS nicola_keys;
// NICOLA親指シフト

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    // NICOLA親指シフト
    MAC_OYA,
    WIN_OYA
    // NICOLA親指シフト
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,   BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LOPTN,           KC_LCMMD, KC_SPC,  MO(MAC_FN),           KC_SPC,             KC_RCMMD,           KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [MAC_FN] = LAYOUT_90_ansi(
        BL_TOGG,    _______,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,    _______,  _______,  BL_DOWN,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,            _______,            _______,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,    _______,  _______,            _______,  _______,  _______,             _______,            _______,            _______,            _______,  _______,  _______),

    [WIN_BASE] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,      KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,      KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,      KC_B,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,            KC_LALT,  KC_SPC,  MO(WIN_FN),           KC_SPC,             KC_RALT,            KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_FN] = LAYOUT_90_ansi(
        BL_TOGG,    _______,  KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  BL_DOWN,   BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,   KC_VOLU,  _______,            _______,
        _______,    _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  KC_UNDS,   KC_INT1,  _______,            _______,
        _______,    BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,   _______,  KC_INT3,            _______,
        _______,    _______,  _______,  BL_DOWN,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,  _______,             _______,            KC_END,
        _______,    _______,            _______,  _______,  _______,  _______,   BAT_LVL,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,   _______,  _______,  _______,
        _______,    _______,  _______,            KC_LNG1,  _______,  _______,             _______,            _______,            KC_INT2,             _______,  _______,  _______),
    // NICOLA親指シフト
    [MAC_OYA] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,   KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  BL_DOWN,   BL_UP,    KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   NG_1,     NG_2,     NG_3,     NG_4,     NG_5,      NG_6,     NG_7,     NG_8,     NG_9,     NG_0,     NG_MINS,  NG_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   NG_Q,     NG_W,     NG_E,     NG_R,     NG_T,      NG_Y,     NG_U,     NG_I,     NG_O,     NG_P,     NG_LBRC,  NG_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  NG_A,     NG_S,     NG_D,     NG_F,     NG_G,      NG_H,     NG_J,     NG_K,     NG_L,     NG_SCLN,  NG_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            NG_Z,     NG_X,     NG_C,     NG_V,      NG_B,     NG_B,     NG_N,     NG_M,     NG_COMM,  NG_DOT,   NG_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LOPTN,           KC_LCMMD, NG_SHFTL, MO(MAC_FN),          NG_SHFTR,           KC_SPC,             KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT),

    [WIN_OYA] = LAYOUT_90_ansi(
        KC_MUTE,    KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,     KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_INS,             KC_DEL,
        MC_1,       KC_GRV,   NG_1,     NG_2,     NG_3,     NG_4,     NG_5,      NG_6,     NG_7,     NG_8,     NG_9,     NG_0,     NG_MINS,  NG_EQL,   KC_BSPC,            KC_PGUP,
        MC_2,       KC_TAB,   NG_Q,     NG_W,     NG_E,     NG_R,     NG_T,      NG_Y,     NG_U,     NG_I,     NG_O,     NG_P,     NG_LBRC,  NG_RBRC,  KC_BSLS,            KC_PGDN,
        MC_3,       KC_CAPS,  NG_A,     NG_S,     NG_D,     NG_F,     NG_G,      NG_H,     NG_J,     NG_K,     NG_L,     NG_SCLN,  NG_QUOT,            KC_ENT,             KC_HOME,
        MC_4,       KC_LSFT,            NG_Z,     NG_X,     NG_C,     NG_V,      NG_B,     NG_B,     NG_N,     NG_M,     NG_COMM,  NG_DOT,   NG_SLSH,  KC_RSFT,  KC_UP,
        MC_5,       KC_LCTL,  KC_LWIN,            KC_LALT,  NG_SHFTL, MO(WIN_FN),          NG_SHFTR,           KC_SPC,             KC_RCTL,            KC_LEFT,  KC_DOWN,  KC_RGHT)
    // NICOLA親指シフト
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [MAC_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [MAC_FN]   = { ENCODER_CCW_CW(BL_DOWN, BL_UP) },
    [WIN_BASE] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_FN]   = { ENCODER_CCW_CW(BL_DOWN, BL_UP) },
    // NICOLA親指シフト
    [MAC_OYA]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [WIN_OYA]  = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) }
    // NICOLA親指シフト
};
#endif // ENCODER_MAP_ENABLE

void matrix_init_user(void) {
    // NICOLA親指シフト
    set_nicola(WIN_OYA);
    // NICOLA親指シフト
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LNG1:
//    case MC_4:
        if (record->event.pressed) {
            // NICOLA親指シフト
            nicola_off();
            // NICOLA親指シフト
        }
        return false;
        break;
    case KC_INT2:
//    case MC_5:
        if (record->event.pressed) {
            // NICOLA親指シフト
            nicola_on();
            // NICOLA親指シフト
        }
        return false;
        break;
    }

    // NICOLA親指シフト
    bool a = true;
    if (nicola_state()) {
        nicola_mode(keycode, record);
        a = process_nicola(keycode, record);
    }
    if (a == false) return false;
    // NICOLA親指シフト

    return true;
}
