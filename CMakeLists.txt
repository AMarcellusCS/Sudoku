cmake_minimum_required(VERSION 3.24)
project(Sudoku)

set(CMAKE_CXX_STANDARD 23)

add_executable(Sudoku src/main.cpp src/Solver.cpp src/Solver.h src/Configuration.cpp src/Configuration.h)
