#pragma once
#include <iostream>
#include <fstream>
#include <memory>
#include <vector>
#include <string>
#include <ios>
#include <algorithm>
#include "Cell.hpp"

struct BoardInfo 
{
    std::vector<Cell> board;
    int width;
    int height;  
};

class BoardParser 
{
    const std::string path;
    std::vector<std::string> lines;

    void getLines() noexcept;
public:
    explicit BoardParser(const std::string& path) noexcept;
    BoardInfo parse() const noexcept;
};
