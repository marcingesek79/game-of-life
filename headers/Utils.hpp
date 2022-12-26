#pragma once
#include <cstdlib>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>
#include "TxtParser.hpp"

namespace Utils {
    void clearTerminal();
    void sleepInMiliseconds(int miliseconds);
    BoardInfo getBoardInfoFromTxtFile(std::string path);
}