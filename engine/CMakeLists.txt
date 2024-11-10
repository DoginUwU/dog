cmake_minimum_required(VERSION 3.29)
project(dog-engine)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE SOURCES lib/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "HEADERS: ${HEADERS}")

add_library(dog-engine STATIC ${SOURCES} ${HEADERS})

target_include_directories(dog-engine PUBLIC include)

add_subdirectory(dependencies/glfw)

target_link_libraries(dog-engine glfw)