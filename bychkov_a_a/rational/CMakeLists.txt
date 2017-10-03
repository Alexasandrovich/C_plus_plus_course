cmake_minimum_required(VERSION 3.8)
project(rational)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES rational.h rational.cpp rational_test.cpp)
add_executable(rational ${SOURCE_FILES})