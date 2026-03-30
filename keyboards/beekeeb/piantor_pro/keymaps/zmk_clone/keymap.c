// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum custom_keycodes {
    MACRO_VIS_ENTER = SAFE_RANGE,
    MACRO_CUT_LINE,
    MACRO_CUT_WORD,
    MACRO_INSERT_LINE_BELOW,
    MACRO_INSERT_LINE_ABOVE,
    MACRO_CUT_LINE_END,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       KC_TAB,    KC_Q,    KC_P,    KC_U,    KC_Y, KC_SCLN,                         KC_K,    KC_F,    KC_L,    KC_R,    KC_B, KC_BSLS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_ESC,  LGUI_T(KC_A), LT(5, KC_O), LSFT_T(KC_E), LT(1, KC_I), KC_G,          KC_D, LT(1, KC_H), RSFT_T(KC_T), LT(2, KC_N), RGUI_T(KC_S),  KC_TAB,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      MO(8),   LT(9, KC_X), LT(7, KC_J), KC_COMM,  KC_EQL, KC_QUOT,                 KC_C,    KC_M,    KC_W, LT(7, KC_V), LT(5, KC_DOT), MO(8),
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                            MO(1), LT(4, KC_BSPC), MO(2),   LT(3, KC_ENT),   LT(3, KC_SPC), KC_RALT
                                      //`--------------------------'  `--------------------------'

  ),

    [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______,  KC_GRV,   KC_LT,   KC_GT, KC_MINS, KC_PIPE,                      KC_CIRC, KC_LCBR, KC_RCBR,  KC_DLR, KC_PIPE, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_EXLM, KC_ASTR, KC_UNDS,  KC_EQL, KC_AMPR,                      KC_HASH, KC_LPRN, KC_RPRN, KC_SCLN, KC_DQUO, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, KC_SLSH, KC_PLUS, KC_LBRC, KC_RBRC, KC_PERC,                        KC_AT, KC_COLN, KC_COMM, KC_QUOT,  KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, KC_COMM,    KC_4,    KC_5,    KC_6, KC_PLUS,                   HYPR(KC_K),LCTL(KC_LEFT),LCTL(KC_UP),LCTL(KC_RGHT),HYPR(KC_B), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______,    KC_0,    KC_1,    KC_2,    KC_3,  KC_EQL,                   HYPR(KC_D),HYPR(KC_H),HYPR(KC_T),HYPR(KC_N),HYPR(KC_S), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______,  KC_DOT,    KC_7,    KC_8,    KC_9, KC_MINS,                   LGUI(KC_0),LGUI(KC_MINS),LGUI(KC_EQL), KC_D, KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, LGUI(KC_Q), LGUI(KC_P), LGUI(KC_U), LGUI(KC_Y), LGUI(KC_P),         LGUI(KC_E), LGUI(KC_F), LGUI(KC_L), LGUI(KC_R), LGUI(KC_B), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, LGUI(KC_A), LGUI(KC_O), LGUI(KC_K), LGUI(KC_I),LGUI(KC_DOT),        KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, LGUI(KC_S), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, LGUI(KC_Z), LGUI(KC_COMM),LGUI(KC_C),LGUI(KC_V),LALT(LGUI(KC_I)),   LGUI(KC_N), LGUI(KC_M), LGUI(KC_W), SGUI(KC_N), LGUI(KC_F), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [4] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, LGUI(KC_Q), SGUI(KC_Z), LGUI(KC_U), LGUI(KC_Y), LGUI(KC_P),         LGUI(KC_E), LGUI(KC_F), LGUI(KC_L), LGUI(KC_R), LGUI(KC_B), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, LGUI(KC_A), LGUI(KC_Z), LGUI(KC_C), LGUI(KC_V), LGUI(KC_DOT),       KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, LGUI(KC_S), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, LGUI(KC_Z), LGUI(KC_COMM),LGUI(KC_C),LGUI(KC_V),LALT(LGUI(KC_I)),   LGUI(KC_N), LGUI(KC_M), LGUI(KC_W), SGUI(KC_N), LGUI(KC_F), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [5] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       SGUI(KC_RGHT), LGUI(KC_SPC), LSA(KC_TAB),LCTL(KC_TAB), LGUI(KC_W), SGUI(KC_T),       LGUI(KC_V),   KC_LEFT,   MACRO_VIS_ENTER, LGUI(KC_Z), KC_RGHT,   SGUI(KC_RGHT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LGUI(KC_RGHT), LGUI(KC_Z),   LGUI(KC_V),   LGUI(KC_C),   SGUI(KC_Z), LSA(KC_DOWN),   LGUI(KC_LEFT),LALT(KC_LEFT),KC_DOWN,   KC_UP,     LALT(KC_RGHT),LGUI(KC_RGHT),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       LSA(KC_UP),    LSA(KC_LEFT), LSFT(KC_UP),  LSFT(KC_DOWN),LSA(KC_RGHT),LSA(KC_DOWN),  MACRO_CUT_LINE,MACRO_CUT_WORD,MACRO_INSERT_LINE_BELOW,MACRO_INSERT_LINE_ABOVE,SGUI(KC_Z),MACRO_CUT_LINE_END,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [7] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, MEH(KC_F3), LGUI(KC_4), LGUI(KC_5), LGUI(KC_6), KC_F14,             SGUI(KC_5), KC_F1,   KC_F2,   KC_F5,  SGUI(KC_2), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, LGUI(KC_0), LGUI(KC_1), LGUI(KC_2), LGUI(KC_3), KC_F15,             SGUI(KC_4), KC_F10,  KC_F11,  KC_F12, SGUI(KC_0), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, MEH(KC_F23),LGUI(KC_7), LGUI(KC_8), LGUI(KC_9), KC_F16,             SGUI(KC_4), KC_F7,   KC_F8,   KC_F9,  SGUI(KC_3), _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [8] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       QK_BOOT, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, QK_BOOT,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, _______, _______, _______, _______, _______,                        _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                           _______, _______, _______,    _______, _______, _______
                                      //`--------------------------'  `--------------------------'
  ),

    [9] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
       _______, LCA(KC_ESC), HYPR(KC_P), LCTL(KC_UP), HYPR(KC_Y), _______,       HYPR(KC_K),LCTL(KC_LEFT),LCTL(KC_UP),LCTL(KC_RGHT),HYPR(KC_B), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, HYPR(KC_A), HYPR(KC_O),LCTL(KC_LEFT),LCTL(KC_RGHT),HYPR(KC_G),   HYPR(KC_D),HYPR(KC_H),HYPR(KC_T),HYPR(KC_N),HYPR(KC_S), _______,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
       _______, SGUI(KC_Q), HYPR(KC_J), _______, _______, _______,               LGUI(KC_0),LGUI(KC_MINS),LGUI(KC_EQL), RGUI(KC_PPLS), KC_DOT, _______,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          _______, _______, _______,    _______, _______, _______
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
    
    if (record->event.pressed) {
        switch (keycode) {
            case MACRO_VIS_ENTER:
                SEND_STRING(SS_TAP(X_LEFT) SS_LALT(SS_TAP(X_LEFT)) SS_LALT(SS_LSFT(SS_TAP(X_RIGHT))));
                return false;
            case MACRO_CUT_LINE:
                SEND_STRING(SS_LCTL("a") SS_LCTL("k") SS_TAP(X_DELETE));
                return false;
            case MACRO_CUT_WORD:
                SEND_STRING(SS_LALT(SS_TAP(X_RIGHT)) SS_LALT(SS_TAP(X_BSPC)));
                return false;
            case MACRO_INSERT_LINE_BELOW:
                SEND_STRING(SS_LGUI(SS_TAP(X_RIGHT)) SS_TAP(X_ENTER));
                return false;
            case MACRO_INSERT_LINE_ABOVE:
                SEND_STRING(SS_LGUI(SS_TAP(X_LEFT)) SS_TAP(X_ENTER) SS_TAP(X_UP));
                return false;
            case MACRO_CUT_LINE_END:
                SEND_STRING(SS_LCTL("k"));
                return false;
        }
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
