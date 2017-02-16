#include "preonic.h"
#include "action_layer.h"
#include "eeconfig.h"

#ifdef AUDIO_ENABLE
    #include "audio.h"
#endif

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum preonic_layers {
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _SYMBOL,
    _LOWER,
    _RAISE,
    _ADJUST,
    _MOUSE,
};

enum preonic_keycodes {
    QWERTY = SAFE_RANGE,
    COLEMAK,
    DVORAK,
    LOWER,
    RAISE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
    {KC_GRV,        KC_1,        KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,                KC_BSPC},
    {KC_TAB,        KC_Q,        KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,                CTL_T(KC_DEL)},
    {ALT_T(KC_ESC), KC_A,        KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), GUI_T(KC_QUOT)},
    {KC_LSFT,       CTL_T(KC_Z), KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  CTL_T(KC_SLSH),      SFT_T(KC_ENT)},
    {KC_RSFT,       KC_LCTL,     KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,               KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
    {KC_GRV,        KC_1,        KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,             KC_BSPC},
    {KC_TAB,        KC_Q,        KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN,          CTL_T(KC_DEL)},
    {ALT_T(KC_ESC), KC_A,        KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    LT(_MOUSE, KC_O), GUI_T(KC_QUOT)},
    {KC_LSFT,       CTL_T(KC_Z), KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  CTL_T(KC_SLSH),   SFT_T(KC_ENT)},
    {KC_RSFT,       KC_LCTL,     KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,            KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
    {KC_GRV,        KC_1,           KC_2,         KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,             KC_BSPC},
    {KC_TAB,        KC_QUOT,        KC_COMM,      KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,             CTL_T(KC_DEL)},
    {ALT_T(KC_ESC), KC_A,           KC_O,         KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    LT(_MOUSE, KC_S), GUI_T(KC_SLSH)},
    {KC_LSFT,       CTL_T(KC_SCLN), KC_Q,         KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    CTL_T(KC_Z),      SFT_T(KC_ENT)},
    {KC_RSFT,       KC_LCTL,        KC_LALT,      KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,            KC_RGHT}
},

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |  _   |  /   |  *   |  -   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |  -   |  {   |   }  |  =   |  7   |  8   |  9   |  +   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      | HOME |  (   |   )  | END  |  4   |  5   |  6   |  =   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |PG_UP |  [   |   ]  |PG_DN |  1   |  2   |  3   |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |  0   |  ,   |  .   |  |   |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = {
    {_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_UNDS, KC_BSLS, KC_ASTR, KC_MINS},
    {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_LCBR, KC_RCBR, KC_EQL,  KC_7,    KC_8,    KC_9,    KC_PLUS},
    {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_HOME, KC_LPRN, KC_RPRN, KC_END,  KC_4,    KC_5,    KC_6,    KC_EQL},
    {_______, XXXXXXX, XXXXXXX, XXXXXXX, KC_PGUP, KC_LBRC, KC_RBRC, KC_PGDN, KC_1,    KC_2,    KC_3,    KC_UNDS},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_COMM, KC_DOT,  KC_PIPE}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 | HOME | PGUP | PGDN | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC},
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL},
    {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_HOME, KC_PGUP, KC_PGDN, KC_END,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
    {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Reset|      |      | PREV | PLAY | NEXT |      |SLCK  |PAUSE |PRTSCR|INSERT|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |CAPLCK|      |      |      |AU_TOG|AGnorm|AGswap|Qwerty|Colemk|Dvorak|SYMBOL|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | SLEEP| WAKE |BLstep|BLtogg| VOL- | VOL+ | MUTE |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
    {_______, RESET,   _______, _______, KC_MPRV, KC_MPLY, KC_PMNS, _______, KC_SLCK, KC_PAUS, KC_PSCR, KC_INS},
    {KC_CAPS, _______, _______, _______, AU_TOG,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  KC_FN1,  _______},
    {_______, KC_SLEP, KC_WAKE, BL_STEP, BL_TOGG, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |MClick| MSUp |RClick| APP  | MENU |RClick| SUp  |Mclick|      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |LClick|MSLeft|MSDown|MRight|LClick|LClick|SLeft |SDown |SRight|      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, KC_BTN3, KC_MS_U, KC_BTN2, KC_APP,  KC_MENU, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______},
    {_______, KC_BTN1, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TOGGLE(_SYMBOL),
};


#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
    {NOTE_B5, 20},
    {NOTE_B6, 8},
    {NOTE_DS6, 20},
    {NOTE_B6, 8}
};

float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_dvorak[][2]  = SONG(DVORAK_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);

float tone_goodbye[][2] = SONG(GOODBYE_SOUND);

float music_scale[][2]  = SONG(MUSIC_SCALE_SOUND);

void startup_user() {
    _delay_ms(20); // gets rid of tick
    PLAY_NOTE_ARRAY(tone_startup, false, 0);
}

void shutdown_user() {
    PLAY_NOTE_ARRAY(tone_goodbye, false, 0);
    _delay_ms(150);
    stop_all_notes();
}

void music_on_user(void) {
    music_scale_user();
}

void music_scale_user(void) {
    PLAY_NOTE_ARRAY(music_scale, false, 0);
}

#endif


void persistant_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case QWERTY:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistant_default_layer_set(1UL << _QWERTY);
        }
        return false;
        break;
    case COLEMAK:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_colemak, false, 0);
            #endif
            persistant_default_layer_set(1UL << _COLEMAK);
        }
        return false;
        break;
    case DVORAK:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
            #endif
            persistant_default_layer_set(1UL << _DVORAK);
        }
        return false;
        break;
    case LOWER:
        if (record->event.pressed) {
            layer_on(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        else {
            layer_off(_LOWER);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    case RAISE:
        if (record->event.pressed) {
            layer_on(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        else {
            layer_off(_RAISE);
            update_tri_layer(_LOWER, _RAISE, _ADJUST);
        }
        return false;
        break;
    }
    return true;
};

void matrix_init_user(void) {
    #ifdef AUDIO_ENABLE
        startup_user();
    #endif
}
