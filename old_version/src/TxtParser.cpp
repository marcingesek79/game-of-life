#include "TxtParser.hpp"

TxtParser::TxtParser(const std::string& path){
    read(path);
}

void TxtParser::read(const std::string& path){
    std::ifstream file{path};
    std::string line;
    while (std::getline(file, line)) {
        std::cout << "kurwa";
        std::cout << line << std::endl;
        mLines.push_back(line);
    }
    if (file.good()){
        std::cout << "gits";
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