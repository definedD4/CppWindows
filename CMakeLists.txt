cmake_minimum_required(VERSION 3.5)
project(CppWindows)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp src/cw/ut/Size.h src/testing/Testing.h)
add_executable(CppWindows ${SOURCE_FILES})