#include "stdio.h"
#include "TXLib.h"
#include "TXWave.h"
#include "FrameGUI.h"
#include "HackTools.h"

int main(int argc, const char* argv[])
{
    if (argc < 2) {
        printf("Usage: %s hack.com\n", argv[0]);

        return -1;
    }

    StartFrame(argv[1]);
}