#define VIAL_KEYBOARD_UID {0x72, 0xD1, 0xB2, 0x31, 0x83, 0x84, 0x13, 0xDE}

#define WEAR_LEVELING_LOGICAL_SIZE (8 * 1024)
#define WEAR_LEVELING_BACKING_SIZE (WEAR_LEVELING_LOGICAL_SIZE * 2)

#define DYNAMIC_KEYMAP_LAYER_COUNT 16

#pragma once

// 1. Enable Per-Key Functions
#ifndef TAPPING_TERM_PER_KEY
#define TAPPING_TERM_PER_KEY
#endif
#ifndef RETRO_TAPPING_PER_KEY
#define RETRO_TAPPING_PER_KEY
#endif
#ifndef TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY
#endif

// 2. Global Mod-Tap Behavior
// Achordion requires Permissive Hold to be enabled to catch fast typing streaks
#define PERMISSIVE_HOLD

// 3. Achordion (Prior Idle) settings
#define ACHORDION_STREAK
