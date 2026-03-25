# Home Row Modifiers (HRM) Concept

This document details the configuration, concepts, and individual timing variables used to manage **Home Row Modifiers (HRM)** and tap-hold keys on the Piantor Pro's QMK firmware, directly migrating and mimicking the heavily-tuned ZMK configuration of the Adv360 keyboard.

## Core Handling Concepts

We are using QMK tap-hold functionality coupled with the **Achordion** library to carefully control intent when typing quickly versus holding for a modifier.

1. **Bilateral Enforcement (Achordion)**
   * **What it does:** Ensures that holding an alphanumeric key (like `A` for Command) will *only* trigger the modifier if the next key you press is on the **opposite hand**.
   * **ZMK Equivalent:** `hold-trigger-key-positions = <KEYS_R/L>`
   * **Exception:** Thumb keys (`Space`, `Enter`, `Backspace`) are exempted and can trigger layers on the same hand.

2. **Prior Idle (`require-prior-idle-ms`)**
   * **What it does:** Dictates how much idle time (not typing) must pass before a key is allowed to be held as a modifier. This heavily prevents accidental holds during rapid, bursting typing speeds.
   * **Current Settings:** Alphas enforce a **150ms** prior-idle delay. Thumb cluster keys have a **0ms** delay to ensure Instant-Layer actuation.

3. **Per-Finger Tapping Terms (`tapping-term-ms`)**
   * **What it does:** Maps precisely *how long* you must hold a specific key before the keyboard determines your intent was a "hold" rather than a "tap".
   * **Customization:** Weaker fingers (Pinkies) typically have much longer tapping terms (`280ms-350ms`) than stronger fingers (Index/Middle: `230ms-260ms`). This is implemented via `get_tapping_term()`.

4. **Quick Tap (`quick-tap-ms`)**
   * **What it does:** Establishes a window (usually `180ms-200ms`) where double-tapping a key cancels the hold action and instead continuously outputs the tap action (e.g., repeatedly firing 'a...a...a' without triggering Command).
   * **Customization:** Configured natively in `get_quick_tap_term()`.

5. **Retro Tapping (`retro-tap`)**
   * **What it does:** Resolves cases where you hold a key past the tapping term, change your mind, and release it without pressing anything else. It will gracefully fall back to outputting the original tap character. Enabled via `get_retro_tapping()`.

6. **Force Hold on Double Tap**
   * **What it does:** For specific thumb keys like `Space` and `Enter`, "Quick Tap" repetition is undesirable. We want them to aggressively trigger their Nav Layer when held, even on consecutive taps.
   * **Configured:** `get_tapping_force_hold()` forces `LT(3, KC_SPC)` and `LT(3, KC_ENT)` to skip quick-tap overrides.

---

## Timings & Mappings Reference

### Left Hand Alphas
| Tap Key | Hold Action | QMK Macro | Tapping Term (ms) | Quick Tap (ms) | Hand/Finger |
|:---:|:---:|:---:|:---:|:---:|:---|
| **A** | Command (`LGUI`) | `LGUI_T(KC_A)` | 350 | 200 | Pinky |
| **O** | Layer 5 (Text Nav) | `LT(5, KC_O)` | 270 | 200 | Ring |
| **E** | Shift (`LSHIFT`) | `LSFT_T(KC_E)` | 250 | 180 | Middle |
| **I** | Layer 1 (Symbols) | `LT(1, KC_I)` | 260 | 200 | Index |
| **X** | Layer 9 (Launcher) | `LT(9, KC_X)` | 350 | - | Pinky Bottom |
| **J** | Layer 7 (Cmd/Num) | `LT(7, KC_J)` | 270 | - | Ring Bottom |

### Right Hand Alphas
| Tap Key | Hold Action | QMK Macro | Tapping Term (ms) | Quick Tap (ms) | Hand/Finger |
|:---:|:---:|:---:|:---:|:---:|:---|
| **H** | Layer 1 (Symbols) | `LT(1, KC_H)` | 234 | 180 | Index |
| **T** | Shift (`RSHIFT`) | `RSFT_T(KC_T)` | 243 | 180 | Middle |
| **N** | Layer 2 (Numbers) | `LT(2, KC_N)` | 243 | 180 | Ring |
| **S** | Command (`RGUI`) | `RGUI_T(KC_S)` | 280 | 180 | Pinky |
| **V** | Layer 7 (Cmd/Num) | `LT(7, KC_V)` | 243 | - | Ring Bottom |
| **.** | Layer 5 (Text Nav) | `LT(5, KC_DOT)` | 280 | 180 | Pinky Bottom |

### Thumb Clusters
| Tap Key | Hold Action | QMK Macro | Tapping Term (ms) | Prior Idle | Force Hold | 
|:---:|:---:|:---:|:---:|:---:|:---:|
| **Backspace** | Layer 4 (Nav Left) | `LT(4, KC_BSPC)` | 220 | 0ms | No |
| **Space** *(Left)* | Layer 3 (Nav Right) | `LT(3, KC_SPC)` | 220 | 0ms | Yes |
| **Enter** *(Right)*| Layer 3 (Nav Right) | `LT(3, KC_ENT)` | 175 | 0ms | Yes |
