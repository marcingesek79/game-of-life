#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <ios>
#include <algorithm>
#include "Cell.hpp"

struct BoardInfo{
    std::vector<std::unique_ptr<Cell>> board;
    int height;
    int width;
};

class TxtParser {
private:
    std::vector<std::string> mLines;

    void read(const std::string& path);
public:
    TxtParser(const std::string& path);
    BoardInfo getBoardInfo();
};
