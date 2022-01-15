#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[0] = LAYOUT(
    KC_NO, KC_Q, KC_W, KC_E, KC_R, KC_T,                              KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_NO,
    KC_NO, KC_A, KC_S, KC_D, KC_F, KC_G,                              KC_H, KC_J, KC_K,    KC_L,   KC_QUOT, KC_NO,
    KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_NO, KC_NO,  KC_NO, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_NO, KC_NO,

    LCTL_T(KC_TAB), LGUI_T(KC_ESC), TT(1), KC_NO, KC_NO, LALT_T(KC_ENT), KC_SPC, LSFT_T(KC_BSPC), KC_NO),

	[1] = LAYOUT(
    KC_NO, KC_1,    KC_2,    KC_3,    KC_4,     KC_5,                                KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_NO,
    KC_NO, KC_A,    KC_LEFT, KC_UP,   KC_RIGHT, KC_GRV,                              KC_BSLS, KC_MINS, KC_EQL,  KC_SCLN, KC_QUOT, KC_NO,
    KC_NO, KC_Z,    KC_X,    KC_DOWN,    KC_V,     KC_B, KC_NO, KC_NO,    KC_NO, KC_NO, KC_LBRC, KC_RBRC, KC_COMM, KC_DOT,  KC_SLSH, KC_NO,

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

// Copy pasta and CMD Z is useful everywhere. Bottom row is transparent so we
// need to remap only DOWN which is above C. This is a hard choice between
// natural PAGE UP DOWN with arrows and CMD C on second layer. Copy pasta is
// stronger in muscle memory so it wins.
const key_override_t copy_on_second_layer = ko_make_basic(
  MOD_MASK_GUI, KC_DOWN, LGUI(KC_C));

// With SHIFT over BACKSPACE it was easy to generate continues BACKSPACE press
// by accident, which is obviously bad. TAPPING_FORCE_HOLD_PER_KEY diables this
// but it means BACKSPACE can now delete only char by char.
// There is CMD BACKSPACE for whole row deletion but this is often too much.
// One word delete is with ALT but this is on the same side as BACKSPACE, so we
// remap it here to CTRL on the left thumb.
const key_override_t word_backspace = ko_make_basic(
  MOD_MASK_CTRL, LSFT_T(KC_BSPC), LALT(KC_BSPC));

// Since CMD C won with PAGE DOWN, we move PAGE UP and DOWN to the right.
const key_override_t page_up_second_layer = ko_make_basic(
  MOD_MASK_GUI, KC_GRV, KC_PGUP);
const key_override_t page_down_second_layer = ko_make_with_layers(
  MOD_MASK_GUI, KC_B, KC_PGDN, 2);

// Real HOME and END is better than CMD arrows because it works with shift in
// terminal. It should also be easier to map in other editors to correct action.
const key_override_t home_override = ko_make_basic(
  MOD_MASK_GUI, KC_LEFT, KC_HOME);
const key_override_t end_override = ko_make_basic(
  MOD_MASK_GUI, KC_RIGHT, KC_END);

// Top row on both layers is for tab management and window switching which is
// more often used than app swithing.

// Switching windows.
const key_override_t cmd_grove_first_layer = ko_make_with_layers(
  MOD_MASK_GUI, KC_Q, LGUI(KC_GRV), 1);
const key_override_t cmd_grove_second_layer = ko_make_with_layers(
  MOD_MASK_GUI, KC_1, LGUI(KC_GRV), 2);

// Closing current tab.
const key_override_t cmd_w_on_second_layer = ko_make_basic(
  MOD_MASK_GUI, KC_2, LGUI(KC_W));

// Tab switching. Note that this cannot be done with CTRL TAB because the
// shifted version for backwards tab switching is triggering the CTRL BACKSPACE
// which deletes the whole words... We cannot change that one to CMD BACKSPACE
// because you cannot use it as a repeated hold since this means CMD SHIFT.
// We still has tab switching on the top tab management row and in general it's
// better to start learning the tab search with CMD SHIFT A.
const key_override_t ctrl_tab_first_layer = ko_make_with_layers(
  MOD_MASK_GUI, KC_E, LCTL(KC_TAB), 1);
const key_override_t ctrl_tab_second_layer = ko_make_with_layers(
  MOD_MASK_GUI, KC_3, LCTL(KC_TAB), 2);

// Refreshing current tab.
const key_override_t cmd_r_on_second_layer = ko_make_basic(
  MOD_MASK_GUI, KC_4, LGUI(KC_R));

// New tab or restore last closed tab (with SHIFT).
const key_override_t cmd_t_on_second_layer = ko_make_basic(
  MOD_MASK_GUI, KC_5, LGUI(KC_T));

// App switching is only on the second layers as it's less used than window
// switching in chrome. It's most often used with terminal where it is useful
// to be on the second layer for the up arrow anyway.
// Also CMD A on the first layer is needed for select-all and tab searching.
const key_override_t cmd_tab_second_layer = ko_make_with_layers(
  MOD_MASK_GUI, KC_A, LGUI(KC_TAB), 2);

// Disabled keys combos may be a step too far and these will be needed in some
// app, so this is an experiment. NOTE: these free combos could be used for
// keyboard management like RGB control.

// CMD D is anoying as it's close to all useful shortcuts and loses focus.
// It adds bookmarks in chrome and splits window in Terminal. Both are more
// anoying than useful.
const key_override_t disable_cmd_d = ko_make_with_layers(
  MOD_MASK_GUI, KC_D, KC_NO, 1);

// CMD UP is anoying because CMD DOWN is copy, so leaving this as a second
// PAGE UP means there is no intuitive way to revert it.
const key_override_t disable_cmd_up = ko_make_with_layers(
  MOD_MASK_GUI, KC_DOWN, KC_NO, 2);

// Disable regular alphas on second layer as these are not intended to be used
// other than in the explicit combos. They are close to arrows and navigation
// and it's anoying when random letters are send on navigation typo.
const key_override_t disable_a_second_layer = ko_make_with_layers_and_negmods(
  0, KC_A, KC_NO, 2, MOD_MASK_GUI);
const key_override_t disable_z_second_layer = ko_make_with_layers_and_negmods(
  0, KC_Z, KC_NO, 2, MOD_MASK_GUI);
const key_override_t disable_x_second_layer = ko_make_with_layers_and_negmods(
  0, KC_X, KC_NO, 2, MOD_MASK_GUI);
const key_override_t disable_c_second_layer = ko_make_with_layers_and_negmods(
  0, KC_C, KC_NO, 2, MOD_MASK_GUI);
const key_override_t disable_v_second_layer = ko_make_with_layers_and_negmods(
  0, KC_V, KC_NO, 2, MOD_MASK_GUI);
const key_override_t disable_b_second_layer = ko_make_with_layers_and_negmods(
  0, KC_B, KC_NO, 2, MOD_MASK_GUI);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &copy_on_second_layer,
    &page_up_second_layer,
    &page_down_second_layer,
    &word_backspace,
    &cmd_w_on_second_layer,
    &cmd_r_on_second_layer,
    &cmd_t_on_second_layer,
    &home_override,
    &end_override,
    &cmd_tab_second_layer,
    &cmd_grove_first_layer,
    &cmd_grove_second_layer,
    &ctrl_tab_first_layer,
    &ctrl_tab_second_layer,
    &disable_a_second_layer,
    &disable_z_second_layer,
    &disable_x_second_layer,
    &disable_c_second_layer,
    &disable_v_second_layer,
    &disable_b_second_layer,
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
