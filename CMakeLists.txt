cmake_minimum_required(VERSION 3.5)

project(ChineseRemainderTheorem LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(Solver)

add_executable(ChineseRemainderTheorem main.cpp)

target_link_libraries(ChineseRemainderTheorem PUBLIC Solver)
target_link_directories(ChineseRemainderTheorem PUBLIC
    "${PROJECT_BINARY_DIR}"
    "${PROJECT_SOURCE_DIR}/Solver")
