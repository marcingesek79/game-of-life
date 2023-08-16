#pragma once
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <array>
#include <iostream>

namespace utils {

    static void clearTerminal()
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    static void sleepInMiliseconds(int miliseconds)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
    }

}