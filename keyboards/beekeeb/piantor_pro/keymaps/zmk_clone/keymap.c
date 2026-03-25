// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
        QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
                                      //`--------------------------'  `--------------------------'
  )
};

#include "achordion.h"

// --- 1. ACHORDION INITIALIZATION ---
void matrix_scan_user(void) {
    achordion_task();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }
    return true; 
}

// --- 2. BILATERAL ENFORCEMENT (ZMK "Trigger Side") ---
bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
    
    // Exception: Allow Thumb keys to trigger layers on the SAME hand
    switch (tap_hold_keycode) {
        case LT(4, KC_BSPC):
        case LT(3, KC_ENT):
        case LT(3, KC_SPC):
            return true;
    }

    // For Alphas: Only allow holds if the next key is on the OPPOSITE hand
    return achordion_opposite_hands(tap_hold_record, other_record);
}

// --- 3. PRIOR IDLE (ZMK "require-prior-idle-ms") ---
uint16_t achordion_streak_chord_timeout(uint16_t tap_hold_keycode, uint16_t next_keycode) {
    // Thumbs have 0ms prior idle delay (instant fire)
    switch (tap_hold_keycode) {
        case LT(4, KC_BSPC):
        case LT(3, KC_ENT):
        case LT(3, KC_SPC):
            return 0;
    }

    // Alphas require 150ms of idle time before a mod can trigger
    return 150; 
}

// --- 4. PER-FINGER TIMING (ZMK "Tapping Term") ---
extern uint16_t qs_get_tapping_term(uint16_t keycode, keyrecord_t *record);

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Left Hand
        case LGUI_T(KC_A): return 350; // Pinky
        case LT(9, KC_X):  return 350; // Pinky Bottom
        case LT(5, KC_O):  return 270; // Ring
        case LT(7, KC_J):  return 270; // Ring Bottom
        case LSFT_T(KC_E): return 250; // Middle
        case LT(1, KC_I):  return 260; // Index
        
        // Right Hand
        case LT(1, KC_H):    return 234; // Index
        case RSFT_T(KC_T):   return 243; // Middle
        case LT(2, KC_N):    return 243; // Ring
        case LT(7, KC_V):    return 243; // Ring Bottom
        case RGUI_T(KC_S):   return 280; // Pinky
        case LT(5, KC_DOT):  return 280; // Pinky Bottom
        
        // Thumbs
        case LT(4, KC_BSPC): return 220;
        case LT(3, KC_ENT):  return 175;
        case LT(3, KC_SPC):  return 220;
    }
    // Global fallback (Reads from the Vial GUI slider!)
    return qs_get_tapping_term(keycode, record); 
}

// --- 5. PER-FINGER QUICK TAP (ZMK "Quick Tap") ---
// Determines the double-tap window for a key to repeat as a tap instead of triggering the hold.
uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Left Hand (200ms generally, but 180ms for Middle)
        case LGUI_T(KC_A): return 200; // Pinky
        case LT(5, KC_O):  return 200; // Ring
        case LSFT_T(KC_E): return 180; // Middle
        case LT(1, KC_I):  return 200; // Index
        
        // Right Hand (180ms for all)
        case LT(1, KC_H):    return 180; // Index
        case RSFT_T(KC_T):   return 180; // Middle
        case LT(2, KC_N):    return 180; // Ring
        case RGUI_T(KC_S):   return 180; // Pinky

        default: return 0; // standard fallback
    }
}

// --- 6. FORCE HOLD (ZMK "Quick Tap: 0") ---
// QMK natively repeats tap characters if you double-tap. 
// We return 'true' for Space/Enter to mimic ZMK's 0ms (disable tap-repeat).
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        // Force these to instantly trigger the hold layer on double-tap
        case LT(3, KC_ENT): 
        case LT(3, KC_SPC): 
            return true; 
        default: 
            return false; // Alphas will output tap repeat normally (e.g. 'aaaa')
    }
}

// --- 6. RETRO TAPPING (ZMK "Retro Tap: Yes") ---
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A): case LT(5, KC_O):   case LSFT_T(KC_E): case LT(1, KC_I):
        case LT(9, KC_X):  case LT(7, KC_J):   case LT(1, KC_H):  case RSFT_T(KC_T):
        case LT(2, KC_N):  case RGUI_T(KC_S):  case LT(7, KC_V):  case LT(5, KC_DOT):
        case LT(4, KC_BSPC): case LT(3, KC_ENT): case LT(3, KC_SPC):
            return true;
        default:
            return false;
    }
}
