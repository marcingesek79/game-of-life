cmake_minimum_required(VERSION 3.8)
project("game-of-life" LANGUAGES CXX)

file(GLOB boards ${CMAKE_CURRENT_SOURCE_DIR}/boards/*.txt)

add_executable(game-of-life "src/main.cpp" "src/Cell.cpp" "src/Board.cpp" "src/TxtParser.cpp" "src/Utils.cpp" ${boards})
target_compile_features(game-of-life PUBLIC cxx_std_17)
target_include_directories(game-of-life PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/headers)