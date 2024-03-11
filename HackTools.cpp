#include "HackTools.h"

void PutNopes(FILE* file, double byte_pos, int count) {

    assert(file != nullptr);

    fseek(file, byte_pos, SEEK_SET);

    for (int i = 0; i < count; i++)
        fputc(NOPE_CODE, file);
}