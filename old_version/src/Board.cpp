#include "Board.hpp"

const std::unique_ptr<Cell>& Board::getCell(int x, int y) const{
    auto it = std::find_if(mBoard.begin(), mBoard.end(), 
    [x, y](const std::unique_ptr<Cell>& cell){
        return cell->getX() == x && cell->getY() == y;
    });
    return *it;
}

bool Board::isInBoundaries(int x, int y) const {
    return x >= 0 && x < mWidth && y >= 0 && y < mHeight;
}

int Board::countNeighbours(int x, int y) const {
    int neighboursCount{0};
    std::array<int, 3> possibleOffsets {-1, 0, 1};

    for (auto yOffset : possibleOffsets){
        for (auto xOffset : possibleOffsets){
            if (yOffset == 0 && xOffset == 0) continue;
            int newY = y + yOffset;
            int newX = x + xOffset;
            if (isInBoundaries(newX, newY) && getCell(newX, newY)->getStatus() == CellStatus::ALIVE ) {
                neighboursCount++;
            }
        }
    }
    return neighboursCount;
}

void Board::print() const {
    std::cout << "TURN: " << mTurn << '\n';
    for (int y{-1}; y < mHeight + 1; y++){
        for (int x{-1}; x < mWidth + 1; x++){
            if (y == -1 || y == mHeight){
                std::cout << '#';
            } else if (x == -1 || x == mWidth){
                std::cout << "#";
            } else {
                std::cout << static_cast<char>(getCell(x, y)->getStatus());
            }   
        }
        std::cout << '\n';
    }
}

void Board::updateCells(const std::vector<std::pair<int, int>>& deadCells, 
                        const std::vector<std::pair<int, int>>& newCells){
    for (const auto& pair : deadCells){
        const_cast<std::unique_ptr<Cell>&>(getCell(pair.first, pair.second))->setStatus(CellStatus::DEAD);
    }
    for (const auto& pair : newCells){
        const_cast<std::unique_ptr<Cell>&>(getCell(pair.first, pair.second))->setStatus(CellStatus::ALIVE);
    }
}

void Board::takeTurn(){
    print();
    std::vector<std::pair<int, int>> deadCells;
    std::vector<std::pair<int, int>> newCells;
    for (int y{}; y < mHeight; y++){
        for (int x{}; x < mWidth; x++){
            uint32_t neighboursCount = countNeighbours(x, y);
            CellStatus cellStatus = getCell(x, y)->getStatus();
            if (cellStatus == CellStatus::DEAD && neighboursCount == 3){
                newCells.push_back(std::make_pair(x, y));
            }
            else if (cellStatus == CellStatus::ALIVE && 
                    (neighboursCount < 2 || neighboursCount > 3)){
                deadCells.push_back(std::make_pair(x, y));
            }
        }
    }
    updateCells(deadCells, newCells);
    mTurn++;
    Utils::sleepInMiliseconds(100);
    //Utils::clearTerminal();
}

void Board::run(int turnLimit){
    //Utils::clearTerminal();
    while (mTurn < turnLimit) {
        takeTurn();
    }
    print();
}

Board::Board(std::string path) : mTurn{}{
    BoardInfo boardInfo = Utils::getBoardInfoFromTxtFile(path);
    mBoard = std::move(boardInfo.board);
    mWidth = boardInfo.width;
    mHeight = boardInfo.height;
}