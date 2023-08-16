#pragma once
#include "utils.hpp"
#include "cell.hpp"
#include "board_parser.hpp"

class Board {
    int width;
    int height;
    int turn;
    std::vector<Cell> board;

    [[nodiscard]] bool isInBoundaries(int x, int y) const noexcept;
    [[nodiscard]] const Cell* getCell(int x, int y) const noexcept;
    [[nodiscard]] Cell* getCell(int x, int y) noexcept;
    [[nodiscard]] int countNeighbours(int x, int y) const noexcept;
    
    void print() const noexcept;
    void updateCells(std::vector<Cell*>& deadCells, std::vector<Cell*>& newCells) noexcept;
    void takeTurn() noexcept;

public:
    void run(int turn_limit) noexcept;
    explicit Board(const std::string& path) noexcept;
};