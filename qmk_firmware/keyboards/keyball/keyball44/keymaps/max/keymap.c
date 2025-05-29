/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// Layers
# define LAYER_DEFAULT 0
# define LAYER_NAVIGATION 1
# define LAYER_NUMBER 2
# define LAYER_FUNCTION 3
# define LAYER_SYMBOL 4
# define LAYER_ACCENTS 5
# define LAYER_TYPING 6

// Left-hand home row mods
#define HOME_A LGUI_T(KC_A)
#define HOME_R LALT_T(KC_R)
#define HOME_S LCTL_T(KC_S)
#define HOME_T LSFT_T(KC_T)
#define HOME_LFT LALT_T(KC_LEFT)
#define HOME_DWN LCTL_T(KC_DOWN)
#define HOME_RGT LSFT_T(KC_RGHT)

// Right-hand home row mods
#define HOME_N RSFT_T(KC_N)
#define HOME_E RCTL_T(KC_E)
#define HOME_I LALT_T(KC_I)
#define HOME_O RGUI_T(KC_O)
#define HOME_J RSFT_T(KC_J)
#define HOME_K RCTL_T(KC_K)
#define HOME_L LALT_T(KC_L)

// Layer mods
#define TO_TYP TO(LAYER_TYPING)
#define TO_DEF TO(LAYER_DEFAULT)
#define LT_SPC LT(LAYER_SYMBOL,KC_SPC)
#define LT_BSPC LT(LAYER_NAVIGATION,KC_BSPC)
#define LT_ENT LT(LAYER_ACCENTS,KC_ENT)
#define LT_DEL LT(LAYER_NUMBER,KC_DEL)
#define LT_BTN1 LT(LAYER_FUNCTION,KC_BTN1)

// Accents
enum unicode_names {
  ACIRC_L,
  ACIRC_U,
  AELIG_L,
  AELIG_U,
  AGRAVE_L,
  AGRAVE_U,
  CCEDIL_L,
  CCEDIL_U,
  EACUTE_L,
  EACUTE_U,
  ECIRC_L,
  ECIRC_U,
  EGRAVE_L,
  EGRAVE_U,
  EUML_L,
  EUML_U,
  ICIRC_L,
  ICIRC_U,
  IUML_L,
  IUML_U,
  OCIRC_L,
  OCIRC_U,
  OELIG_L,
  OELIG_U,
  UCIRC_L,
  UCIRC_U,
  UGRAVE_L,
  UGRAVE_U,
  UUML_L,
  UUML_U,
  YUML_L,
  YUML_U,
};

const uint32_t PROGMEM unicode_map[] = {
  [ACIRC_L] = 0x00E2,
  [ACIRC_U] = 0x00C2,
  [AELIG_L] = 0x00E6,
  [AELIG_U] = 0x00C6,
  [AGRAVE_L] = 0x00E0,
  [AGRAVE_U] = 0x00C0,
  [CCEDIL_L] = 0x00E7,
  [CCEDIL_U] = 0x00C7,
  [EACUTE_L] = 0x00E9,
  [EACUTE_U] = 0x00C9,
  [ECIRC_L] = 0x00EA,
  [ECIRC_U] = 0x00CA,
  [EGRAVE_L] = 0x00E8,
  [EGRAVE_U] = 0x00C8,
  [EUML_L] = 0x00EB,
  [EUML_U] = 0x00CB,
  [ICIRC_L] = 0x00EE,
  [ICIRC_U] = 0x00CE,
  [IUML_L] = 0x00EF,
  [IUML_U] = 0x00CF,
  [OCIRC_L] = 0x00F4,
  [OCIRC_U] = 0x00D4,
  [OELIG_L] = 0x0153,
  [OELIG_U] = 0x0152,
  [UCIRC_L] = 0x00FB,
  [UCIRC_U] = 0x00DB,
  [UGRAVE_L] = 0x00F9,
  [UGRAVE_U] = 0x00D9,
  [UUML_L] = 0x00FC,
  [UUML_U] = 0x00DC,
  [YUML_L] = 0x00FF,
  [YUML_U] = 0x0178,
};

#define ACIRC UP(ACIRC_L,ACIRC_U)
#define AELIG UP(AELIG_L,AELIG_U)
#define AGRAVE UP(AGRAVE_L,AGRAVE_U)
#define CCEDIL UP(CCEDIL_L,CCEDIL_U)
#define EACUTE UP(EACUTE_L,EACUTE_U)
#define ECIRC UP(ECIRC_L,ECIRC_U)
#define EGRAVE UP(EGRAVE_L,EGRAVE_U)
#define EUML UP(EUML_L,EUML_U)
#define ICIRC UP(ICIRC_L,ICIRC_U)
#define IUML UP(IUML_L,IUML_U)
#define OCIRC UP(OCIRC_L,OCIRC_U)
#define OELIG UP(OELIG_L,OELIG_U)
#define UCIRC UP(UCIRC_L,UCIRC_U)
#define UGRAVE UP(UGRAVE_L,UGRAVE_U)
#define UUML UP(UUML_L,UUML_U)
#define YUML UP(YUML_L,YUML_U)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default
  [LAYER_DEFAULT] = LAYOUT_universal(
    KC_TAB   , KC_Q     , KC_W     , KC_F     , KC_P     , KC_B     ,                                        KC_J     , KC_L     , KC_U     , KC_Y     , KC_SCLN  , KC_MINUS ,
    KC_ESC   , HOME_A   , HOME_R   , HOME_S   , HOME_T   , KC_G     ,                                        KC_M     , HOME_N   , HOME_E   , HOME_I   , HOME_O   , KC_QUOTE ,
    TO_TYP   , KC_Z     , KC_X     , KC_C     , KC_D     , KC_V     ,                                        KC_K     , KC_H     , KC_COMM  , KC_DOT   , KC_SLSH  , KC_BSLS  ,
               CW_TOGG  , LT_BTN1  , KC_BTN2  , LT_BSPC  , LT_DEL   ,                                        LT_ENT   , LT_SPC   , KC_NO    , KC_NO    , UC_NEXT
  ),

  [LAYER_NAVIGATION] = LAYOUT_universal(
    _______  ,  _______ , _______  , KC_UP   , _______ , _______  ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  ,  _______ , HOME_LFT , HOME_DWN, HOME_RGT, _______  ,                                         KC_H     , HOME_J   , HOME_K   , HOME_L   , _______  , _______  ,
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
                _______ , _______  , _______ , _______ , _______  ,                                         _______  , _______  , _______  , _______  , _______
  ),

  [LAYER_NUMBER] = LAYOUT_universal(
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         KC_PLUS  , KC_7     , KC_8     , KC_9     , KC_EQL   , _______  ,
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         KC_MINUS , KC_4     , KC_5     , KC_6     , KC_MINUS , _______  ,
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         KC_DOT   , KC_1     , KC_2     , KC_3     , KC_DOT   , _______  ,
                _______ , _______  , _______ , _______ , _______  ,                                         _______  , KC_0     , _______  , _______  , _______
  ),

  [LAYER_FUNCTION] = LAYOUT_universal(
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         KC_VOLU  , KC_F7    , KC_F8    , KC_F9    , KC_F10   , _______  ,
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         KC_VOLD  , KC_F4    , KC_F5    , KC_F6    , KC_F11   , _______  ,
    _______  ,  _______ , _______  , _______ , _______ , _______  ,                                         KC_MNXT  , KC_F1    , KC_F2    , KC_F3    , KC_F12   , _______  ,
                _______ , _______  , _______ , _______ , _______  ,                                         KC_MPRV  , KC_MPLY  , _______  , _______  , _______
  ),

  [LAYER_SYMBOL] = LAYOUT_universal(
    KC_HASH  ,  KC_LBRC , KC_LCBR  , KC_RCBR , KC_RBRC , KC_PERC  ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
    KC_CIRC  ,  KC_LPRN , KC_COLN  , KC_EQL  , KC_RPRN , KC_DLR   ,                                         _______  , KC_PLUS  , KC_MINUS , KC_SLSH  , KC_ASTR  , _______  ,
    KC_GRV   ,  KC_LT   , KC_EXLM  , KC_MINUS, KC_GT   , KC_QUES  ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
                KC_PIPE , KC_AMPR  , KC_TILD , KC_UNDS , KC_AT    ,                                         _______  , _______  , _______  , _______  , _______
  ),

  [LAYER_ACCENTS] = LAYOUT_universal(
    _______  ,  ICIRC   , ACIRC    , ICIRC   , AGRAVE  , AELIG    ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
    YUML     ,  EUML    , ECIRC    , EACUTE  , EGRAVE  , CCEDIL   ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
    _______  ,  UUML    , UCIRC    , OCIRC   , UGRAVE  , OELIG    ,                                         _______  , _______  , _______  , _______  , _______  , _______  ,
                _______ , _______  , _______ , _______ , _______  ,                                         _______  , _______  , _______  , _______  , _______
  ),

  [LAYER_TYPING] = LAYOUT_universal(
    KC_LGUI  ,  _______ , _______  , _______ , _______ , _______  ,                                         _______  , _______  , _______  , _______  , _______  , KC_LALT ,
    KC_LCTL  ,  KC_A    , KC_R     , KC_S    , KC_T    , _______  ,                                         _______  , KC_N     , KC_E     , KC_I     , KC_O     , _______ ,
    KC_LSFT  ,  _______ , _______  , _______ , _______ , _______  ,                                         _______  , _______  , _______  , _______  , _______  , KC_LSFT ,
                _______ , _______  , _______ , _______ , _______  ,                                         _______  , _______  , _______  , _______  , TO_DEF
  ),

  //[3] = LAYOUT_universal(
  //  RGB_TOG  , AML_TO   , AML_I50  , AML_D50  , _______  , _______  ,                                        RGB_M_P  , RGB_M_B  , RGB_M_R  , RGB_M_SW , RGB_M_SN , RGB_M_K  ,
  //  RGB_MOD  , RGB_HUI  , RGB_SAI  , RGB_VAI  , _______  , SCRL_DVI ,                                        RGB_M_X  , RGB_M_G  , RGB_M_T  , RGB_M_TW , _______  , _______  ,
  //  RGB_RMOD , RGB_HUD  , RGB_SAD  , RGB_VAD  , _______  , SCRL_DVD ,                                        CPI_D1K  , CPI_D100 , CPI_I100 , CPI_I1K  , _______  , KBC_SAVE ,
  //                QK_BOOT  , KBC_RST  , _______  ,        _______  , _______  ,                   _______  , _______  , _______       , KBC_RST  , QK_BOOT
  //),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is LAYER_NAVIGATION
    keyball_set_scroll_mode(get_highest_layer(state) == LAYER_NAVIGATION);
    return state;
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
