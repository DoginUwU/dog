cmake_minimum_required(VERSION 3.0.0)
project(engine VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/glm)
add_subdirectory(dependencies/glad)

file(GLOB SOURCES lib/**/*.cpp lib/*.cpp)
file(GLOB HEADERS include/**/*.hpp include/*.hpp)

file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})

add_library(engine STATIC ${SOURCES} ${HEADERS})

target_link_libraries(engine glfw)
target_link_libraries(engine glm)
target_link_libraries(engine glad)

include_directories(include)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
