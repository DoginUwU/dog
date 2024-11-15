cmake_minimum_required(VERSION 3.29)
project(stb)

set(CMAKE_CXX_STANDARD 26)

add_library(stb STATIC stb_image.cpp)

target_include_directories(stb PUBLIC ./)
set_target_properties(stb PROPERTIES LINKER_LANGUAGE CXX)