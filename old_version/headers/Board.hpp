#pragma once
#include "Utils.hpp"
#include <memory>
#include <array>

class Board {
private:
    int mWidth;
    int mHeight;
    int mTurn;
    std::vector<std::unique_ptr<Cell>> mBoard;

    bool isInBoundaries(int x, int y) const;
    int countNeighbours(int x, int y) const;
    const std::unique_ptr<Cell>& getCell(int x, int y) const;
    void print() const;
    void updateCells(const std::vector<std::pair<int, int>>& deadCells, 
                     const std::vector<std::pair<int, int>>& newCells);
    void takeTurn();

public:
    void run(int turnLimit);
    Board(std::string path);
};