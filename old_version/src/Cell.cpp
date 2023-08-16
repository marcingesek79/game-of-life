#include "Cell.hpp"

Cell::Cell(int x, int y, CellStatus status) : mX{x}, mY{y}, mStatus{status}{}

int Cell::getX() const { return mX; }
int Cell::getY() const { return mY; }
CellStatus Cell::getStatus() const { return mStatus; }
void Cell::setStatus(CellStatus status) { mStatus = status; }