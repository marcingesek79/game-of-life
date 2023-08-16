#include "board.hpp"

bool Board::isInBoundaries(int x, int y) const noexcept
{
    return x >= 0 && x < this->width && y >= 0 && y < this->height;
}

const Cell* Board::getCell(int x, int y) const noexcept
{
    auto cell = std::find_if(this->board.begin(), this->board.end(),
        [x, y](auto& cell)
        {
            return cell.getX() == x && cell.getY() == y;
        });
    return &(*cell);
}

Cell* Board::getCell(int x, int y) noexcept
{
    auto cell = std::find_if(this->board.begin(), this->board.end(),
        [x, y](auto& cell) 
        {
            return cell.getX() == x && cell.getY() == y;
        });
    return &(*cell);
}

int Board::countNeighbours(int x, int y) const noexcept
{
    int neighbours_count{};
    std::array<int, 3> possible_offsets{ -1, 0, 1 };

    for (auto y_offset : possible_offsets)
    {
        for (auto x_offset : possible_offsets)
        {
            if (y_offset == 0 && x_offset == 0)
                continue;

            auto new_y = y + y_offset;
            auto new_x = x + x_offset;

            if (this->isInBoundaries(new_x, new_y) && this->getCell(new_x, new_y)->status == CellStatus::ALIVE)
            {
                neighbours_count++;
            }
        }
    }
    return neighbours_count;
}

void Board::print() const noexcept
{
    std::cout << "TURN: " << turn << '\n';
    for (int y{-1}; y < height + 1; y++)
    {
        for (int x{-1}; x < width + 1; x++)
        {
            if (y == -1 || y == height)
            {
                std::cout << '#';
            }
            else if (x == -1 || x == width)
            {
                std::cout << "#";
            }
            else
            {
                auto status = getCell(x, y)->status;
                std::cout << static_cast<char>(status);
            }
        }
        std::cout << '\n';
    }
}

void Board::updateCells(std::vector<Cell*>& dead_cells, std::vector<Cell*>& new_cells) noexcept
{
    for (auto& cell : dead_cells) 
    {
        cell->status = CellStatus::DEAD;
    }
    for (auto& cell : new_cells)
    {
        cell->status = CellStatus::ALIVE;
    }
}

void Board::takeTurn() noexcept
{
    this->print();
    std::vector<Cell*> dead_cells;
    std::vector<Cell*> new_cells;

    for (int y{}; y < height; y++)
    {
        for (int x{}; x < width; x++)
        {
            auto neighbours_count = this->countNeighbours(x, y);
            auto cell = this->getCell(x, y);

            if (cell->status == CellStatus::DEAD && neighbours_count == 3) 
            {
                new_cells.emplace_back(cell);
            }
            else if (cell->status == CellStatus::ALIVE &&
                    (neighbours_count < 2 || neighbours_count > 3)) 
            {
                dead_cells.emplace_back(cell);
            }
        }
    }

    this->updateCells(dead_cells, new_cells);
    this->turn++;
}

void Board::run(int turn_limit) noexcept
{
    utils::clearTerminal();
    
    while (this->turn < turn_limit)
    {
        this->takeTurn();
        utils::sleep();
        utils::clearTerminal();
    }
    this->print();
}

Board::Board(const std::string& path) noexcept
    : width{}, height{}, turn{}, board{}
{
    BoardParser parser{ path };
    auto board_info = parser.parse();
    this->board = board_info.board;
    this->width = board_info.width;
    this->height = board_info.height;
}