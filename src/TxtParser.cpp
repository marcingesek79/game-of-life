#include "../headers/TxtParser.hpp"
#include "../headers/Cell.hpp"
#include <algorithm>
#include <ios>
#include <memory>

TxtParser::TxtParser(const std::string& path){
    read(path);
}

void TxtParser::read(const std::string& path){
    std::ifstream file{path};
    if (file.good()){
        std::string line;
        while (std::getline(file, line)){
            mLines.push_back(line);
        }
    } else {
        std::cout << "git";
    }
}

BoardInfo TxtParser::getBoardInfo(){
    std::vector<std::unique_ptr<Cell>> board;
    int y{}, x{}, height{}, width{};
    for (const auto& line : mLines){
        x = 0;
        for (const auto& character : line){
            CellStatus status = CellStatus::DEAD;
            if (character == '1'){
                status = CellStatus::ALIVE;
            }
            auto cell = std::make_unique<Cell>(x, y, status);
            board.push_back(std::move(cell));
            x++;
        }
        y++;
    }
    width = x;
    height = y;
    return std::move(BoardInfo{std::move(board), height, width});
}