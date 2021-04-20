#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BL,
    _F1,
    _F2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* 
     * ┌─────┬─────┬┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐     ┌─────┬─────┬─────┬─────┬─────┬─────┬───────────┬─────┐
     * │(F1) │TILDE││ESC  │  1  │  2  │  3  │  4  │  5  │  6  │     │  7  │  8  │  9  │  0  │  -  │  =  │BACKSPACE  │(HOM)│
     * ├─────┼─────┼┼─────┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┘  ┌──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬────────┼─────┤
     * │F3   │F4   ││TAB     │  Q  │  W  │  E  │  R  │  T  │     │  Y  │  U  │  I  │  O  │  P  │  [  │  ]  │   ISO  │DEL  │
     * ├─────┼─────┼┼────────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐    └┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┬────┴┐       ├─────┤
     * │F5   │F6   ││FN2/&CAPS│  A  │  S  │  D  │  F  │  G  │     │  H  │  J  │  K  │  L  │  ;  │  '  │  \  │ENTER  │PGUP │
     * ├─────┼─────┼┼──────┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┐  └──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴──┬──┴─────┴─┬─────┼─────┤
     * │F7   │F8   ││SHIFT │  \  │  Z  │  X  │  C  │  V  │  B  │     │  N  │  M  │  ,  │  .  │  /  │SHIFT     │ UP  │PGDN │
     * ├─────┼─────┼┼──────┼─────┴─┬───┴──┬──┴───┬─┴─────┴─────┤     ├─────┴─────┴────┬┴────┬┴────┬┴────┬─────┼─────┼─────┤
     * │F9   │F10  ││CTRL  │L_GUI  │ALT   │FN1   │SPACE        │     │SPACE           │FN2  │ALT  │CTRL │LEFT │DOWN │RIGHT│
     * └─────┴─────┴┴──────┴───────┴──────┴──────┴─────────────┘     └────────────────┴─────┴─────┴─────┴─────┴─────┴─────┘
     */
    [_BL] = LAYOUT_65_iso_with_macro(
    // ┌────────┬───────┬┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        KC_F1,   KC_GRV,  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,             KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_HOME, \
    // ├────────┼───────┼┼────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
        KC_F3,   KC_F4,   KC_TAB,       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,              KC_DEL,  \
    // ├────────┼───────┼┼─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴───┐        ├────────┤
        KC_F5,   KC_F6,   LT(_F2,KC_CAPS),KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_NUHS,   KC_ENT,  KC_PGUP, \
    // ├────────┼───────┼┼──────────┬────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───┐    └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┼────────┼────────┤
        KC_F7,   KC_F8,   KC_LSFT,   KC_NUBS,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,      KC_UP,   KC_PGDN, \
    // ├────────┼───────┼┼──────────┼──────────┴┬───────┴──┬─────┴─────┬──┴────────┴──────┤          ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
        KC_F9,   KC_F10,  KC_LCTL,   KC_LGUI,    KC_LALT,   MO(_F1),    KC_SPC,                       _______,    KC_SPC,    MO(_F2), KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    // └────────┴───────┴┴──────────┴───────────┴──────────┴───────────┴──────────────────┘          └──────────────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
    ),

    [_F1] = LAYOUT_65_iso_with_macro(
    // ┌────────┬───────┬┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,  KC_DEL,  KC_DEL,  _______, \
    // ├────────┼───────┼┼────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
        _______, _______, RGB_TOG,      RGB_MOD, _______, KC_UP,   _______, _______,          _______, _______, _______, _______, _______, _______, _______,              _______, \
    // ├────────┼───────┼┼─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴───┐        ├────────┤
        _______, _______, _______,        _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,          _______, _______, _______, _______, _______, _______, _______,   _______, _______, \
    // ├────────┼───────┼┼──────────┬────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───┐    └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┼────────┼────────┤
        _______, _______, _______,   _______,   _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,      _______, _______, \
    // ├────────┼───────┼┼──────────┼──────────┴┬───────┴──┬─────┴─────┬──┴────────┴──────┤          ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
        _______, _______, KC_TILD,   _______,    _______,   _______,    _______,                      _______,   _______,    _______, _______, _______, _______, _______, _______ 
    // └────────┴───────┴┴──────────┴───────────┴──────────┴───────────┴──────────────────┘          └──────────────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
    ), 

    [_F2] = LAYOUT_65_iso_with_macro(
    // ┌────────┬───────┬┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐        ┌────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┬────────┐
        _______, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F7,            KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11, KC_F12,  KC_DEL,  KC_DEL,  _______, \
    // ├────────┼───────┼┼────────┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┘    ┌───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────┬───┴────────┼────────┤
        _______, _______, _______,      KC_MPRV, KC_MPLY, KC_MNXT, _______, _______,          _______, KC_PGUP, KC_UP,   KC_PGDN, KC_PSCR, KC_DEL,  _______,              _______, \
    // ├────────┼───────┼┼─────────────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┐      └─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴─┬──────┴───┐        ├────────┤
        _______, _______, _______,        _______, KC_VOLD, KC_VOLU, KC_MUTE, _______,          KC_HOME, KC_LEFT, KC_DOWN, KC_RGHT, _______, KC_INS,  _______,   _______, _______, \
    // ├────────┼───────┼┼──────────┬────┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴───┐    └─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴─────┬──┴──────────┼────────┼────────┤
        _______, _______, _______,   _______,   _______, _______, _______, _______, _______,          KC_END,  _______, _______, _______, _______, _______,      _______, _______, \
    // ├────────┼───────┼┼──────────┼──────────┴┬───────┴──┬─────┴─────┬──┴────────┴──────┤          ├────────┴────────┴────┬───┴────┬───┴────┬───┴────┬────────┼────────┼────────┤
        _______, _______, _______,   _______,    _______,   _______,    _______,                      _______,   _______,    _______, KC_RGUI, _______, _______, _______, _______ 
    // └────────┴───────┴┴──────────┴───────────┴──────────┴───────────┴──────────────────┘          └──────────────────────┴────────┴────────┴────────┴────────┴────────┴────────┘
    )
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
};

#define MODS_SHIFT (get_mods() & MOD_BIT(KC_LSHIFT) || get_mods() & MOD_BIT(KC_RSHIFT))
#define MODS_CTRL  (get_mods() & MOD_BIT(KC_LCTL) || get_mods() & MOD_BIT(KC_RCTRL))
#define MODS_ALT   (get_mods() & MOD_BIT(KC_LALT) || get_mods() & MOD_BIT(KC_RALT))

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    
    // Icelandic quote macros:
    //   hold left alt, then press keypad 0132, then release alt: „
    //   hold left alt, then press keypad 0147, then release alt: “
    case KC_1:
        if (record->event.pressed && MODS_CTRL && MODS_ALT) {
            clear_mods();
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P3) SS_TAP(X_P2) SS_UP(X_LALT));
            return false; // No further processing by QMK
        }
        break;
    case KC_2:
    if (record->event.pressed && MODS_CTRL && MODS_ALT) {
            clear_mods();
            SEND_STRING(SS_DOWN(X_LALT) SS_TAP(X_P0) SS_TAP(X_P1) SS_TAP(X_P4) SS_TAP(X_P7) SS_UP(X_LALT));
            return false; // No further processing by QMK
        }
        break;
    }
    return true;
};