cmake_minimum_required(VERSION 3.24)
project(Sudoku)

set(CMAKE_CXX_STANDARD 23)

add_executable(Sudoku main.cpp cmake-build-debug/Solver.cpp cmake-build-debug/Solver.h cmake-build-debug/Configuration.cpp cmake-build-debug/Configuration.h)
