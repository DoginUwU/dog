cmake_minimum_required(VERSION 3.29)
project(game)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE SOURCES src/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "HEADERS: ${HEADERS}")

add_executable(game ${SOURCES} ${HEADERS})

target_include_directories(game PRIVATE include ../engine/include)
target_link_libraries(game dog-engine)