#pragma once
#include <memory>

enum class CellStatus : char {
    ALIVE = 'x',
    DEAD = ' '
};

class Cell{
private:
    const int mX;
    const int mY;
    CellStatus mStatus;
public:
    Cell(int x, int y, CellStatus status);
    int getX() const;
    int getY() const;
    CellStatus getStatus() const;
    void setStatus(CellStatus status);
};