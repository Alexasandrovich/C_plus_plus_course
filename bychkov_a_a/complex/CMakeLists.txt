cmake_minimum_required(VERSION 3.8)
project(Complex)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES complex.h complex_test.cpp)
add_executable(Complex ${SOURCE_FILES} complex.cpp)