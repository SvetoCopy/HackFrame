#include "FrameGUI.h"

void StartFrame(const char* file_to_hack) {

    txPlaySound(MENU_SOUND_NAME);
    txCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT);

    HDC background_menu    = txLoadImage(MENU_BACKGROUND_IMG);
    HDC background_success = txLoadImage(SUCCESS_BACKGROUND_IMG);
    HDC background_button  = txLoadImage(BUTTON_BACKGROUND_IMD);

    if (!background_menu)
        txMessageBox("Не могу загрузить фон для меню", "Да, я скопировал это из примера");

    if (!background_button)
        txMessageBox("Не могу загрузить фон для кнопки", "Да, я скопировал это из примера");

    txBitBlt(txDC(), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, background_menu, 0, 0);
    txBitBlt(txDC(), HACKBUTTON_X, HACKBUTTON_Y, HACKBUTTON_WIDTH, HACKBUTTON_HEIGHT, background_button, 0, 0);

    bool is_pressed = false;
    while (!txGetAsyncKeyState(VK_ESCAPE)) {

        if (HackButtonPressed() && !is_pressed) {

            txPlaySound(NULL);
            txPlaySound(SUCCESS_SOUND_NAME);

            if (!background_success)
                txMessageBox("Не могу загрузить фон для взлома", "Да, я скопировал это из примера");

            txBitBlt(txDC(), 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, background_success, 0, 0);

            FILE* file = {};

            fopen_s(&file, file_to_hack, "r+");
            PutNopes(file, PWD_CHECKER_POS, NOPE_COUNT);

            is_pressed++;
        }
    }
    
    txDeleteDC(background_button);
    txDeleteDC(background_menu);
    txDeleteDC(background_success);
}
