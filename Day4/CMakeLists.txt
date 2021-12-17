cmake_minimum_required(VERSION 3.21)
project(Day4)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)

include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day4 main.cpp day4_1.cpp Tile.cpp Tile.h Grid.cpp Grid.h day4_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day4 LINK_PUBLIC ${AOC_LIB})
