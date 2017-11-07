cmake_minimum_required(VERSION 3.8)
project(CMake)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrixR.cpp matrixR.h matrix_test.cpp matrixU.cpp matrixU.h)
add_executable(CMake ${SOURCE_FILES})