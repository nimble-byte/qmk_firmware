/* Copyright 2022 Til Goepfert (@nimble-byte)

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

#include "rgb_matrix_map.h"

// Custom Layers
enum layers { _BASE, _FN, _NUMPAD };

enum custom_keycodes {
    FINDER = SAFE_RANGE, // actually PowerToys Run, but does not matter
    EMO_SHR,             // `\_("/)_/`
    EMO_SAD,             // :'-(
    EMO_CON,             // (^o^)
    EMO_CRY,             // (T_T)
};

#define TG_NUM TG(_NUMPAD)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

//      ESC      F1       F2       F3       F4       F5       F6       F7       F8       F9       F10      F11      F12	     Prt           Rotary(Mute)
//      ~        1        2        3        4        5        6        7        8        9        0         -       (=)	     BackSpc           Del
//      Tab      Q        W        E        R        T        Y        U        I        O        P        [        ]        \                 PgUp
//      Caps     A        S        D        F        G        H        J        K        L        ;        "                 Enter             PgDn
//      Sh_L              Z        X        C        V        B        N        M        ,        .        ?                 Sh_R     Up       End
//      Ct_L     Win_L    Alt_L                               SPACE                               Alt_R    FN       Ct_R     Left     Down     Right


    // The FN key by default maps to a momentary toggle to layer 1 to provide access to the QK_BOOT key (to put the board into bootloader mode). Without
    // this mapping, you have to open the case to hit the button on the bottom of the PCB (near the USB cable attachment) while plugging in the USB
    // cable to get the board into bootloader mode - definitely not fun when you're working on your QMK builds. Remove this and put it back to KC_RGUI
    // if that's your preference.
    //
    // To put the keyboard in bootloader mode, use FN+backslash. If you accidentally put it into bootloader, you can just unplug the USB cable and
    // it'll be back to normal when you plug it back in.
    //
    // This keyboard defaults to 6KRO instead of NKRO for compatibility reasons (some KVMs and BIOSes are incompatible with NKRO).
    // Since this is, among other things, a "gaming" keyboard, a key combination to enable NKRO on the fly is provided for convenience.
    // Press Fn+N to toggle between 6KRO and NKRO. This setting is persisted to the EEPROM and thus persists between restarts.
    [_BASE] = LAYOUT(
        KC_ESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME,          KC_MUTE,
        KC_GRV, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGUP,
        KC_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,           KC_PGDN,
        KC_LSFT,         KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, KC_UP,   KC_END,
        KC_LCTL, KC_LGUI, KC_LALT,                           KC_SPC,                             KC_RALT, MO(_FN), KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN] = LAYOUT(
        EE_CLR,  _______, _______, _______, _______, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_END,           KC_MPLY,
        _______, EMO_SHR, EMO_SAD, EMO_CON, EMO_CRY, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, RGB_SAD, RGB_VAI, RGB_SAI, NK_TOGG, _______, _______, _______, _______, _______,  TG_NUM, _______, _______, QK_BOOT,          _______,
        KC_CAPS, RGB_HUD, RGB_VAD, RGB_HUI, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______,  KC_NUM, _______, _______, _______, _______,          _______, RGB_MOD, _______,
        RGB_TOG, _______, _______,                            KC_MPLY,                            _______, _______, _______, RGB_SPD, RGB_RMOD, RGB_SPI
    ),

    [_NUMPAD] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______,   KC_P7,   KC_P8,   KC_P9, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______,   KC_P4,   KC_P5,   KC_P6, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______,   KC_P1,   KC_P2,   KC_P3, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______,   KC_P0, KC_PDOT, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______

    /**
    [X] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          _______,
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______,
        _______, _______, _______,                            _______,                            _______, _______, _______, _______, _______, _______
     */
    ),
};
// clang-format on

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case EMO_SHR:
            if (record->event.pressed)
                send_string("\\_(\"/)_/");
            else
                unregister_code16(keycode);
            break;
        case EMO_CRY:
            if (record->event.pressed)
                send_string("(T_T)");
            else
                unregister_code16(keycode);
            break;
        case EMO_CON:
            if (record->event.pressed)
                send_string("(o.O)");
            else
                unregister_code16(keycode);
            break;
        case EMO_SAD:
            if (record->event.pressed)
                send_string(":'-(");
            else
                unregister_code16(keycode);
            break;
        default:
            break;
    }
    return true;
}

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (IS_LAYER_ON(_FN)) {
        if (clockwise) {
            tap_code(KC_MNXT);
        } else {
            tap_code(KC_MPRV);
        }
    } else {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return false;
}
#endif // ENCODER_ENABLE

#ifdef RGB_MATRIX_ENABLE
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    led_t led_state = host_keyboard_led_state();
    if (led_state.caps_lock) {
        // TODO: find proper way to invert the current color
        for (uint8_t i = 0; i < ARRAYSIZE(LED_SIDES_UPPER); i++) {
            rgb_matrix_set_color(LED_SIDES_UPPER[i], RGB_BORDEAUX);
        }
        rgb_matrix_set_color(LED_CAPS, RGB_BORDEAUX);
        rgb_matrix_set_color(LED_FN, RGB_BORDEAUX);
    }

    // light up sides in dark red, if numlock is OFF
    if (!led_state.num_lock) {
        for (uint8_t i = 0; i < ARRAYSIZE(LED_SIDES_LOWER); i++) {
            rgb_matrix_set_color(LED_SIDES_LOWER[i], RGB_BORDEAUX);
        }
        rgb_matrix_set_color(LED_N, RGB_BORDEAUX);
        rgb_matrix_set_color(LED_FN, RGB_BORDEAUX);
    }

    // LEDs are always blocked in rows, because I think about them that way
    switch (get_highest_layer(layer_state)) {
        case _FN:
            rgb_matrix_set_color(LED_ESC, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F5, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F6, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F7, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F8, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F9, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F10, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_F11, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_HOME, RGB_DMAGENTA);

            rgb_matrix_set_color(LED_1, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_2, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_3, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_4, RGB_DMAGENTA);

            rgb_matrix_set_color(LED_Q, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_W, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_E, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_R, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_P, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_BSLS, RGB_DMAGENTA);

            rgb_matrix_set_color(LED_CAPS, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_A, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_S, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_D, RGB_DMAGENTA);

            rgb_matrix_set_color(LED_N, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_UP, RGB_DMAGENTA);

            rgb_matrix_set_color(LED_LCTL, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_SPC, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_LEFT, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_DOWN, RGB_DMAGENTA);
            rgb_matrix_set_color(LED_RIGHT, RGB_DMAGENTA);
            break;
        case _NUMPAD:
            for (uint8_t i = 0; i < ARRAYSIZE(LED_LIST_NUMPAD); i++) {
                rgb_matrix_set_color(LED_LIST_NUMPAD[i], RGB_DMAGENTA);
            }
            break;
        default:
            // rgb_matrix_set_color(LED_F3, RGB_DMAGENTA);
            break;
    }
    return false;
}
#endif // RGB_MATRIX_ENABLE
