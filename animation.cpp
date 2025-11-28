#include <iostream>
#include <chrono>
#include <thread>
#include <windows.h>

// Some MinGW versions do NOT define this
#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

void enableVTMode() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}   

void blockMove() {
    for (int i = 0; i <= 20; i++) {
        std::cout << "\rMoving: [" << std::string(i, '#') << "]";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    std::cout << std::endl;
}

void blockUnblock() {
    for (int i = 20; i >= 0; i--) {
        std::cout << "\rUnblocking: [" << std::string(i, '#') << "]";
        std::this_thread::sleep_for(std::chrono::milliseconds(150));
    }
    std::cout << std::endl;
}

void fillAndEmpty() {
    std::string purple = "\033[35m";
    std::string reset  = "\033[0m";

    for (int i = 1; i <= 20; i++) {
        std::cout << "\r[" << purple << std::string(i, '#') << reset << "]";
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }

    for (int i = 20; i >= 1; i--) {
        std::cout << "\r[" << purple << std::string(i, '#') << reset << "]";
        std::this_thread::sleep_for(std::chrono::milliseconds(80));
    }

    std::cout << std::endl;
}

int main() {
    enableVTMode();
    fillAndEmpty();
    return 0;
}
