cmake_minimum_required(VERSION 3.8)
project(vec3dT)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vec3dT_test.cpp vec3dT.h)
add_executable(vec3dT ${SOURCE_FILES} vec3dT_test.cpp vec3dT.h)