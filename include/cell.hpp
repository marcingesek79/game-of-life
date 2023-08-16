#pragma once

enum class CellStatus : char 
{
    ALIVE = 'x',
    DEAD = ' '
};

class Cell 
{
    int x;
    int y;

public:
    CellStatus status;

    Cell(int x, int y, CellStatus status) noexcept
        : x{ x }, y{ y }, status{ status }
    {
    }

    int getX() const noexcept
    {
        return this->x;
    }

    int getY() const noexcept
    {
        return this->y;
    }
};