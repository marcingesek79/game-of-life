#pragma once
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <vector>
#include <array>
#include <iostream>

namespace utils {

    static constexpr int SLEEP_TIME{ 100 };

    static void clearTerminal()
    {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    static void sleep()
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(SLEEP_TIME));
    }

}