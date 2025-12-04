#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

#include "ui/LabelMenu.hpp"

using namespace std;

// Some MinGW versions do NOT define this
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enableVTMode()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

void animationLoading()
{
    welcome();
    cout << "\r\033[62C" ;
    for (int i = 0; i <= 30; i++)
    {
        cout << "\r\033[63C" << BOLD_RED << string(i, '-') << "/" << RESET;
        this_thread::sleep_for(chrono::milliseconds(50));
    }
    for (int i = 0; i <= 30; i++)
    {
        cout << "\r\033[63C" << BOLD_GREEN << string(i, '#') << BOLD_GREEN << "/" << RESET;
        this_thread::sleep_for(chrono::milliseconds(50));
    }

    cout << endl;
    cout << endl;

}
