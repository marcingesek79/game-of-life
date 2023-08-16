#include "board_parser.hpp"

BoardParser::BoardParser(const std::string& path) noexcept
    : path{path}, lines{}
{
    this->getLines();
}

void BoardParser::getLines() noexcept
{
    std::ifstream file{ this->path };
    std::string line{};

    if (file.good()) 
    {
        while (std::getline(file, line))
        {
            this->lines.emplace_back(line);
        }
    }
    else 
    {
        std::cout << "Cannot read the file" << std::endl;
    }
}

BoardInfo BoardParser::parse() const noexcept 
{
    std::vector<Cell> board{};
    int x{}, y{};

    for (const auto& line : this->lines)
    {
        x = 0;
        for (const auto& character : line)
        {
            CellStatus status = (character == '1') ? CellStatus::ALIVE : CellStatus::DEAD;
            Cell cell{ x, y, status };
            board.emplace_back(cell);
            x++;
        }
        y++;
    }

    return { board, x, y };
}