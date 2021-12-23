cmake_minimum_required(VERSION 3.21)
project(Day12)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day12 main.cpp day12_1.cpp day12_2.cpp Cave.cpp Cave.h)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day12 LINK_PUBLIC ${AOC_LIB})