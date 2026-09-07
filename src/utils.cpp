#include <iostream>
#include <limits>
#include <cstdlib>
#include "utils.h"

void clearScreen() {
    // Note: system() is only a security concern when its argument is built
    // from user input (command injection). Here the string is a fixed
    // literal chosen at compile time, never touched by user input, so
    // calling it is safe. We just need the right command per OS.
#if defined(_WIN32)
    system("cls");   // کوتیشن اضافه شد
#else
    system("clear"); // کوتیشن اضافه شد
#endif
}
