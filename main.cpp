﻿#include "board.hpp"

int main()
{
    const std::string PATH = "pulsar.txt";
    const int TURN_LIMIT = 500;

    Board board{ PATH };
    board.run(TURN_LIMIT);

    return 0;
}