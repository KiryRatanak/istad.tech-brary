#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

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

void fillAndEmpty()
{
    string red = "\033[31m";
    string green = "\033[32m";
    string reset = "\033[0m";
    cout << "[\r\033[62C" ;
    for (int i = 0; i <= 30; i++)
    {
        cout << "\r\033[63C" << red << string(i, '-') << "/" << reset;
        this_thread::sleep_for(chrono::milliseconds(80));
    }
    cout << "]";
    for (int i = 0; i <= 30; i++)
    {
        cout << "\r\033[63C" << green << string(i, '#') << green << "/" << reset;
        this_thread::sleep_for(chrono::milliseconds(80));
    }

    cout << "]" <<endl;

}

int main()
{
    enableVTMode();
    fillAndEmpty();
    return 0;
}
