cmake_minimum_required(VERSION 3.21)
project(Day11)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day11 main.cpp day11_1.cpp day11_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day11 LINK_PUBLIC ${AOC_LIB})