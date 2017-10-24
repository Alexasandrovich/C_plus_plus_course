cmake_minimum_required(VERSION 3.8)
project(kvanternion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES  kvanternion.h kvanternion.cpp kvanternion_test.cpp)
add_executable(kvanternion ${SOURCE_FILES} kvanternion.h kvanternion.cpp kvanternion_test.cpp)