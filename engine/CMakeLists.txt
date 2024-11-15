cmake_minimum_required(VERSION 3.29)
project(dog-engine)

set(CMAKE_CXX_STANDARD 26)

file(GLOB_RECURSE SOURCES lib/*.cpp)
file(GLOB_RECURSE HEADERS include/*.hpp)

message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "HEADERS: ${HEADERS}")

add_library(dog-engine STATIC ${SOURCES} ${HEADERS} dependencies)

target_include_directories(dog-engine PUBLIC include)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glad)
add_subdirectory(dependencies/glm)
add_subdirectory(dependencies/stb)

set_target_properties(glm PROPERTIES CXX_STANDARD 23)
set_target_properties(glm PROPERTIES CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)

target_link_libraries(dog-engine glfw glad glm stb ${OPENGL_LIBRARIES})
