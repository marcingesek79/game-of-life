cmake_minimum_required(VERSION 3.10)
project(game_of_life)
set(CMAKE_CXX_STANDARD 14)

file(GLOB SRC "src/*.cpp")
file(COPY boards DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(game_of_life ${SRC})