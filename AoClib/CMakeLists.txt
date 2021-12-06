cmake_minimum_required(VERSION 3.21)
project(AoClib)

set(CMAKE_CXX_STANDARD 14)

add_library(AoC AoC.cpp AoC.h AoC.inl)

add_executable(Test AoC.cpp AoC.h AoC.inl test_AoClib.cpp)

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    add_custom_command(TARGET AoC POST_BUILD COMMAND cp ${CMAKE_BINARY_DIR}/libAoC.a ${CMAKE_SOURCE_DIR}/..)
endif()