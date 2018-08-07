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
    _CUSTOM,
    _QWERTY,
    _COLEMAK,
    _DVORAK,
    _SYMBOL,
    _MOUSE,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum preonic_keycodes {
    CUSTOM = SAFE_RANGE,
    QWERTY,
    COLEMAK,
    DVORAK,
    SYMBOL,
    MOUSE,
    LOWER,
    RAISE,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Custom
 * ,-----------------------------------------------------------------------------------.
 * |   =  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |~ / RS| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_CUSTOM] = {
    {KC_EQL,         KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,                KC_MINS},
    {KC_TAB,         KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,                KC_BSPC},
    {CTL_T(KC_ESC),  KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), GUI_T(KC_QUOT)},
    {KC_LSFT,        KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,             SFT_T(KC_ENT)},
    {RSFT_T(KC_GRV), KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,               KC_RGHT}
},

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = {
    {KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,                KC_BSPC},
    {KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,  KC_T,   KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,                CTL_T(KC_DEL)},
    {CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,  KC_G,   KC_H,   KC_J,  KC_K,    KC_L,    LT(_MOUSE, KC_SCLN), GUI_T(KC_QUOT)},
    {KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,             SFT_T(KC_ENT)},
    {KC_RSFT,       KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,               KC_RGHT}
},

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = {
    {KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,             KC_BSPC},
    {KC_TAB,        KC_Q,    KC_W,    KC_F,    KC_P,  KC_G,   KC_J,   KC_L,  KC_U,    KC_Y,    KC_SCLN,          CTL_T(KC_DEL)},
    {CTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,  KC_D,   KC_H,   KC_N,  KC_E,    KC_I,    LT(_MOUSE, KC_O), GUI_T(KC_QUOT)},
    {KC_LSFT,       KC_Z,    KC_X,    KC_C,    KC_V,  KC_B,   KC_K,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,          SFT_T(KC_ENT)},
    {KC_RSFT,       KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,            KC_RGHT}
},

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |RShift| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = {
    {KC_GRV,        KC_1,    KC_2,    KC_3,    KC_4,  KC_5,   KC_6,   KC_7,  KC_8,    KC_9,    KC_0,             KC_BSPC},
    {KC_TAB,        KC_QUOT, KC_COMM, KC_DOT,  KC_P,  KC_Y,   KC_F,   KC_G,  KC_C,    KC_R,    KC_L,             CTL_T(KC_DEL)},
    {CTL_T(KC_ESC), KC_A,    KC_O,    KC_E,    KC_U,  KC_I,   KC_D,   KC_H,  KC_T,    KC_N,    LT(_MOUSE, KC_S), GUI_T(KC_SLSH)},
    {KC_LSFT,       KC_SCLN, KC_Q,    KC_J,    KC_K,  KC_X,   KC_B,   KC_M,  KC_W,    KC_V,    KC_Z,             SFT_T(KC_ENT)},
    {KC_RSFT,       KC_LCTL, KC_LALT, KC_LGUI, LOWER, KC_SPC, KC_SPC, RAISE, KC_LEFT, KC_DOWN, KC_UP,            KC_RGHT}
},

/* Symbol
 * ,-----------------------------------------------------------------------------------.
 * |NumLck|  7   |  8   |  9   |  /   | Bksp | HOME |  7   |  8   |  9   |  /   | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  4   |  5   |  6   |  *   | Del  | PGDN |  4   |  5   |  6   |  *   | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |  1   |  2   |  3   |  -   |  =   | PGUP |  1   |  2   |  3   |  -   |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Shift |  0   |  .   |  ,   |  +   |Enter | END  |  0   |  .   |  ,   |  +   |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_SYMBOL] = {
    {KC_NLCK, KC_P7,   KC_P8,   KC_P9,   KC_PSLS, KC_BSPC, KC_HOME, KC_7,    KC_8,    KC_9,    KC_SLSH, KC_BSPC},
    {_______, KC_P4,   KC_P5,   KC_P6,   KC_PAST, KC_DEL,  KC_PGUP, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_DEL},
    {KC_ESC,  KC_P1,   KC_P2,   KC_P3,   KC_PMNS, KC_PEQL, KC_PGDN, KC_1,    KC_2,    KC_3,    KC_MINS, KC_EQL},
    {_______, KC_P0,   KC_PDOT, KC_PCMM, KC_PPLS, KC_PENT, KC_END,  KC_0,    KC_DOT,  KC_COMM, KC_PLUS, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MClick| MSUp |RClick|      |      |RClick| SUp  |Mclick|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MSLeft|MSDown|MRight|LClick|LClick|SLeft |SDown |SRight|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = {
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______},
    {_______, _______, KC_BTN3, KC_MS_U, KC_BTN2, _______, _______, KC_BTN2, KC_WH_U, KC_BTN3, _______, _______},
    {_______, _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_BTN1, KC_BTN1, KC_WH_L, KC_WH_D, KC_WH_R, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | HOME | END  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = {
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC},
    {KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL},
    {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______},
    {_______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / | PGUP | PGDN |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | RAlt | RGUI |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = {
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC},
    {KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL},
    {KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS},
    {_______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______},
    {_______, _______, KC_RALT, KC_RGUI, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY}
},

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CAPLCK| Reset| WAKE |      |      |SYMBOL|MOUSE |      |      |      |PRTSCR|INSERT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |SLEEP |      |AU_TOG|AGnorm|AGswap|Qwerty|Colemk|Dvorak|Custom|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |BLstep|      | MUTE | F14  | F15  |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = {
    {KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12},
    {KC_CAPS, RESET,   KC_WAKE, _______, _______, KC_FN1,  KC_FN2,  _______, _______, _______, KC_PSCR, KC_INS},
    {_______, _______, KC_SLEP, _______, AU_TOG,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, DVORAK,  CUSTOM,  _______},
    {_______, _______, _______, _______, _______, BL_STEP, _______, KC_MUTE, KC_F14,  KC_F15,  _______, _______},
    {_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
},

};


const uint16_t PROGMEM fn_actions[] = {
    [1] = ACTION_LAYER_TOGGLE(_SYMBOL),
    [2] = ACTION_LAYER_TOGGLE(_MOUSE),
};


#ifdef AUDIO_ENABLE

float tone_startup[][2] = {
    {NOTE_B5, 20},
    {NOTE_B6, 8},
    {NOTE_DS6, 20},
    {NOTE_B6, 8}
};

#define CUSTOM_SOUND \
    ED_NOTE(_E7  ),  \
    S__NOTE(_REST),  \
    ED_NOTE(_GS7 ),  \
    S__NOTE(_REST),  \
    E__NOTE(_GS6 ),  \
    E__NOTE(_A6  ),

float tone_custom[][2]  = SONG(CUSTOM_SOUND);
float tone_qwerty[][2]  = SONG(QWERTY_SOUND);
float tone_dvorak[][2]  = SONG(DVORAK_SOUND);
float tone_colemak[][2] = SONG(COLEMAK_SOUND);

float tone_symbol[][2]  = SONG(COIN_SOUND);
float tone_mouse[][2]   = SONG(ODE_TO_JOY);

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


void persistent_default_layer_set(uint16_t default_layer) {
    eeconfig_update_default_layer(default_layer);
    default_layer_set(default_layer);
}


bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
    case CUSTOM:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_custom, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_CUSTOM);
        }
        return false;
        break;
    case QWERTY:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_QWERTY);
        }
        return false;
        break;
    case COLEMAK:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_colemak, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_COLEMAK);
        }
        return false;
        break;
    case DVORAK:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_DVORAK);
        }
        return false;
        break;
    case SYMBOL:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_symbol, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_SYMBOL);
        }
        return false;
        break;
    case MOUSE:
        if (record->event.pressed) {
            #ifdef AUDIO_ENABLE
                PLAY_NOTE_ARRAY(tone_mouse, false, 0);
            #endif
            persistent_default_layer_set(1UL<<_MOUSE);
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
