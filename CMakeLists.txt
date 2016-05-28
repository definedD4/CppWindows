cmake_minimum_required(VERSION 3.5)
project(CppWindows)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp
        src/cw/ut/Size.h
        src/testing/Testing.h
        src/cw/ut/Point.h
        src/cw/st/Area.cpp
        src/cw/st/Area.h src/cw/ut/AreaTreeUtils.h)

add_executable(CppWindows ${SOURCE_FILES})