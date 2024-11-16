cmake_minimum_required(VERSION 3.29)
project(tiny_obj_loader)

add_library(tiny_obj_loader tiny_obj_loader.hpp tiny_obj_loader.cpp)
target_include_directories(tiny_obj_loader PUBLIC ./)