cmake_minimum_required(VERSION 3.0.0)
project(cpp-voxel VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(engine)

file(GLOB SOURCES game/src/**/*.cpp game/src/*.cpp)
file(GLOB HEADERS game/include/**/*.hpp game/include/*.hpp)

message(STATUS "SOURCES: ${SOURCES}")
message(STATUS "HEADERS: ${HEADERS}")

add_executable(cpp-voxel ${SOURCES} ${HEADERS}) 

target_link_libraries(cpp-voxel PUBLIC engine)
target_include_directories(cpp-voxel PUBLIC engine/include)

include_directories(game/include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
