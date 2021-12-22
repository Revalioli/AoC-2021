cmake_minimum_required(VERSION 3.21)
project(Day10)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day10 main.cpp day10_1.cpp day10_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day10 LINK_PUBLIC ${AOC_LIB})