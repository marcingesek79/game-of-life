#include "Utils.hpp"

void Utils::clearTerminal(){
    #ifdef _WIN32
        system("cls");
    #endif
    #ifndef _WIN32
        system("clear");
    #endif
}

void Utils::sleepInMiliseconds(int miliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

BoardInfo Utils::getBoardInfoFromTxtFile(std::string path){
    TxtParser txtParser{path};
    return std::move(txtParser.getBoardInfo());
}
