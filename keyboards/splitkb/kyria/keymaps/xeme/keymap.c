#include QMK_KEYBOARD_H

/* THIS FILE WAS GENERATED!
 *
 * This file was generated by qmk json2c. You may or may not want to
 * edit it directly.
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
    KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO,
    KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G,                              KC_H, KC_J, KC_K,    KC_L,   KC_QUOT, KC_NO,
    KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO,  KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO,

    LCTL_T(KC_TAB), LGUI_T(KC_ESC), TT(1), KC_NO, KC_NO, LALT_T(KC_ENT), KC_SPC, LSFT_T(KC_BSPC), KC_NO),

	[1] = LAYOUT(
    KC_NO, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_NO, KC_TRNS, KC_LEFT, KC_UP,   KC_RIGHT, KC_GRV,                              KC_BSLS, KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_NO,
    KC_NO, KC_TRNS, KC_TRNS, KC_DOWN, KC_TRNS,  KC_B, KC_NO, KC_NO,    KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, KC_NO,

    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO, KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO)
};


bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LSFT_T(KC_BSPC):
      return true;
    default:
      return false;
  }
}

const key_override_t copy_on_second_layer = ko_make_basic(
  MOD_MASK_GUI,
  KC_DOWN,
  LGUI(KC_C));

const key_override_t page_up_second_layer = ko_make_basic(
  MOD_MASK_GUI,
  KC_GRV,
  KC_PGUP);

const key_override_t page_down_second_layer = ko_make_with_layers(
  MOD_MASK_GUI,
  KC_B,
  KC_PGDN,
  2);

const key_override_t word_backspace = ko_make_basic(
  MOD_MASK_CTRL,
  LSFT_T(KC_BSPC),
  LALT(KC_BSPC));

const key_override_t cmd_q_on_second_layer = ko_make_basic(
  MOD_MASK_GUI,
  KC_1,
  LGUI(KC_Q));

const key_override_t cmd_w_on_second_layer = ko_make_basic(
  MOD_MASK_GUI,
  KC_2,
  LGUI(KC_W));

const key_override_t cmd_e_on_second_layer = ko_make_basic(
  MOD_MASK_GUI,
  KC_3,
  LGUI(KC_E));

const key_override_t cmd_r_on_second_layer = ko_make_basic(
  MOD_MASK_GUI,
  KC_4,
  LGUI(KC_R));

const key_override_t home_override = ko_make_basic(
  MOD_MASK_GUI,
  KC_LEFT,
  KC_HOME);

const key_override_t end_override = ko_make_basic(
  MOD_MASK_GUI,
  KC_RIGHT,
  KC_END);

/*
const key_override_t next_app_override = ko_make_basic(
  MOD_MASK_CTRL,
  KC_DOWN,
  LGUI(KC_GRAVE));

const key_override_t previous_app_override = ko_make_basic(
  MOD_MASK_CTRL,
  KC_UP,
  LSG(KC_GRAVE));

const key_override_t next_window_override = ko_make_basic(
  MOD_MASK_CS,
  KC_DOWN,
  LGUI(KC_TAB));

const key_override_t previous_window_override = ko_make_basic(
  MOD_MASK_CS,
  KC_UP,
  LGUI(KC_TAB));
*/
// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &copy_on_second_layer,
    &page_up_second_layer,
    &page_down_second_layer,
    &word_backspace,
    &cmd_q_on_second_layer,
    &cmd_w_on_second_layer,
    &cmd_e_on_second_layer,
    &cmd_r_on_second_layer,
    &home_override,
    &end_override,
    // &next_app_override,
    // &previous_app_override,
    // These won't work for now because they have conflicting modifiers. This
    // maybe possible to be fixed with ko_make_with_layers_and_negmods.
    // Also we need to somehow recreate the behaviour when cmd is held and app
    // switching pop up stays open.
//    &next_window_override,
//    &previous_window_override,
    NULL // Null terminate the array of overrides!
};

void default_led(void) {
  // Default hue saturation and value.
  rgblight_sethsv(80, 255, 100);
}

void keyboard_post_init_user(void) {
   default_led();
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, 1)) {
      rgblight_sethsv(80, 255, 255);
    } else {
      default_led();
    }
    return state;
}
