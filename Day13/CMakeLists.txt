cmake_minimum_required(VERSION 3.21)
project(Day13)

set(CMAKE_CXX_STANDARD 14)

configure_file(input.txt . COPYONLY)
include_directories(${CMAKE_SOURCE_DIR}/../AoClib)

add_executable(Day13 main.cpp day13_1.cpp day13_2.cpp)

find_library(AOC_LIB AoC ${CMAKE_SOURCE_DIR}/..)
target_link_libraries(Day13 LINK_PUBLIC ${AOC_LIB})