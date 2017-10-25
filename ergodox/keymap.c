// Netable differences vs. the default firmware for the ErgoDox EZ:
// 1. The Cmd key is now on the right side, making Cmd+Space easier.
// 2. The media keys work on OSX (But not on Windows).
#include "ez.h"
#include "action_layer.h"

enum keyboard_layers {
  BASE = 0, // default layer
  NUMS,     // numbers + symbols
  MOVE,     // vim-like movement
  AFK,
};

enum keyboard_macros {
  MACRO_AFK = 0,
  MACRO_WAKE,
  MACRO_LAYER_NUMS,
  MACRO_LAYER_MOVE,
  MACRO_VIM_B,
  MACRO_VIM_W,
  MACRO_VIM_ENDLINE,
  MACRO_VIM_BGNLINE,
  MACRO_DELETE_WORD,
};

#define BF_AFK M(MACRO_AFK)
#define BF_WAKE M(MACRO_WAKE)
#define BF_NUMS M(MACRO_LAYER_NUMS)
#define BF_MOVE M(MACRO_LAYER_MOVE)
#define VIM_B M(MACRO_VIM_B)
#define VIM_W M(MACRO_VIM_W)
#define VIM_END M(MACRO_VIM_ENDLINE)
#define VIM_BGN M(MACRO_VIM_BGNLINE)
#define BF_DEL M(MACRO_DELETE_WORD)
#define BF_LYR(layer) MT(MO(layer), TG(layer)) // Mod or toggle layer (hold vs tap)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |    `   |   1  |   2  |   3  |   4  |   5  |   6  |           | Power|   7  |   8  |   9  |   0  |   -  |   =    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |  [   |           |   ]  |   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |   '    |
 * |--------+------+------+------+------+------|  L1  |           |  L1  |------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Hyper |  F19 |AltShf| Left | Right|                                       |  Up  | Down |Ctrl/E|  F19 |  Meh |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  V-  |  V+  |       | Next |Play/Pau|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |  Vx  |       | Prev |        |      |
 *                                 | Space| LGUI |------|       |------|  Bsp   | Enter|
 *                                 |      |      | LAlt |       | LAlt |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = KEYMAP(  // layer 0 : default
        // left hand
        KC_GRV,         KC_1,         KC_2,   KC_3,   KC_4,   KC_5,   KC_6,
        KC_TAB,         KC_Q,         KC_W,   KC_E,   KC_R,   KC_T,   KC_LBRC,
        CTL_T(KC_ESC),  KC_A,         KC_S,   KC_D,   KC_F,   KC_G,
        KC_LSFT,        KC_Z,         KC_X,   KC_C,   KC_V,   KC_B,   BF_NUMS,
        ALL_T(KC_NO),   KC_F19,       KC_LALT,BF_MOVE,BF_NUMS,
                                                      KC_VOLD,KC_VOLU,
                                                              KC_MUTE,
                                               KC_SPC,KC_LGUI,KC_LALT,

        // right hand
        BF_AFK,    KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS,          KC_EQL,
        KC_RBRC,     KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,             KC_BSLS,
                     KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN,          KC_QUOT,
        BF_NUMS,KC_N, KC_M,   KC_COMM,KC_DOT, KC_SLSH,          KC_RSFT,
                        BF_NUMS,BF_MOVE,CTL_T(KC_ESC),KC_F19,     MEH_T(KC_NO),
        KC_MNXT,        KC_MPLY,
        KC_MPRV,
        KC_LALT,KC_BSPC,KC_ENT
    ),
/* Keymap 1: Number Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   #  |   $  |   %  |      |           |      |   ^  |   &  |   *  |   (  |   )  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   1  |   2  |   3  |   4  |   5  |------|           |------|   6  |   7  |   8  |   9  |   0  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[NUMS] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_HASH,KC_DLR, KC_PERC,KC_TRNS,
       KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,
       KC_TRNS,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,

       // right hand
       KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_CIRC, KC_AMPR,KC_ASTR, KC_LPRN, KC_RPRN, KC_TRNS,
                KC_6 ,   KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
       KC_TRNS, KC_TRNS, KC_1,   KC_2,    KC_3,    KC_SLSH, KC_TRNS,
                         KC_TRNS,KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),

/* Keymap 2: Movement Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |VIM W |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------| LEFT | DOWN |  UP  |RIGHT |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |VIM B |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MOVE] = KEYMAP(
       // left hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,VIM_W,  KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,VIM_BGN,VIM_END,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,VIM_B,  KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,

       // right hand
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
               KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
                       KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,KC_TRNS,
       KC_TRNS,KC_TRNS,
       KC_TRNS,
       KC_TRNS,BF_DEL ,KC_TRNS
),

/* Keymap 3: AFK Layer
 * All keys wake
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[AFK] = KEYMAP(
       // left hand
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
                                       BF_WAKE,BF_WAKE,
                                               BF_WAKE,
                               BF_WAKE,BF_WAKE,BF_WAKE,

       // right hand
       KC_TRNS,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
                BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
                         BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,BF_WAKE,
       BF_WAKE,BF_WAKE,
       BF_WAKE,
       BF_WAKE,BF_WAKE,BF_WAKE
),
};

const uint16_t PROGMEM fn_actions[] = {
};

uint8_t layer_stack = 0;
void rgblight_reset_mode(void) {
  if (layer_stack != 0) return;
  rgblight_setrgb(20,0,35);  // purple
  rgblight_mode(3);
};

void mod_layer_with_rgb(keyrecord_t *record, uint8_t layer, uint8_t r, uint8_t g, uint8_t b) {
  if (record->event.pressed) {
    rgblight_mode(1);
    layer_stack++;
    layer_on(layer);
    rgblight_setrgb(r, g, b);
  } else {
    layer_stack--;
    layer_off(layer);
    rgblight_reset_mode();
  }
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  bool shift_active = (
    keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))
  );

  // MACRODOWN only works in this function
  switch(id) {
    case MACRO_VIM_B:
      return MACRODOWN(D(LALT), T(LEFT), U(LALT), END);
    break;
    case MACRO_VIM_W:
      return MACRODOWN(D(LALT), T(RGHT), U(LALT), END);
    break;
    case MACRO_VIM_BGNLINE:
      return MACRODOWN(D(LGUI), T(LEFT), U(LGUI), END);
    break;
    case MACRO_VIM_ENDLINE:
      return MACRODOWN(D(LGUI), T(RGHT), U(LGUI), END);
    break;
    case MACRO_DELETE_WORD:
      if (!shift_active) return MACRODOWN(D(LALT), T(BSPC), U(LALT), END);
      clear_mods();
      return MACRODOWN(D(LGUI), T(BSPC), U(LGUI), END);
    break;
    case MACRO_AFK:
      if (!record->event.pressed) return MACRO_NONE;
      action_macro_play(
        MACRO(I(50), D(LCTL), D(LSFT), T(POWER), U(LSFT), U(LCTL), END)
      );
      layer_on(AFK);
      rgblight_setrgb(35,0,0); //red
      rgblight_mode(4); // knight mode
    break;
    case MACRO_WAKE:
      if (!record->event.pressed) return MACRO_NONE;
      layer_off(AFK);
      rgblight_reset_mode();
      return MACRO(T(WAKE), T(SPC), END);
    break;
    case MACRO_LAYER_NUMS:
      mod_layer_with_rgb(record, NUMS, 0, 20, 20);
    break;
    case MACRO_LAYER_MOVE:
      mod_layer_with_rgb(record, MOVE, 35, 10, 0);
    break;
  }
  return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_enable();
  rgblight_reset_mode();
};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
  uint8_t layer = biton32(layer_state);

  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case BASE:
    break;
    case NUMS:
      ergodox_right_led_1_on();
    break;
    case MOVE:
      ergodox_right_led_2_on();
    break;
    case AFK:
      ergodox_right_led_3_on();
    break;
    default:
      break;
  }

};
