#include "Board.hpp"

int main()
{
    std::string path = "boards/pulsar.txt";
    Board board{path};
    board.run(500);
    return 0;
}