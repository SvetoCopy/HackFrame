#pragma once

#include "TXLib.h"
#include "HackTools.h"

#define HackButtonPressed()                                                                        \
        ((txMouseButtons() & 1)                                                          &&        \
        (txMouseX() >= HACKBUTTON_X && txMouseX() <= (HACKBUTTON_X + HACKBUTTON_WIDTH)) &&         \
        (txMouseY() >= HACKBUTTON_Y && txMouseY() <= (HACKBUTTON_Y + HACKBUTTON_HEIGHT)))

#define MENU_SOUND_NAME          "resources\\ghoul.wav"
#define SUCCESS_SOUND_NAME       "resources\\success.wav"
#define MENU_BACKGROUND_IMG      "resources\\Screenshot_30.bmp"
#define SUCCESS_BACKGROUND_IMG   "resources\\cow_img.bmp"
#define BUTTON_BACKGROUND_IMD    "resources\\button_img.bmp"

const double HACKBUTTON_X = 720;
const double HACKBUTTON_Y = 200;

const double HACKBUTTON_HEIGHT = 100;
const double HACKBUTTON_WIDTH  = 300;

const int WINDOW_HEIGHT = 520;
const int WINDOW_WIDTH  = 1115;

const int PWD_CHECKER_POS = 102;
const int NOPE_COUNT      = 6;

void StartFrame(const char* file_to_hack);