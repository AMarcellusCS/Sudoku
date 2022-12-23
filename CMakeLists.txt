cmake_minimum_required(VERSION 3.24)
project(Sudoku)

set(CMAKE_CXX_STANDARD 23)

add_executable(Sudoku main.cpp Solver.cpp Solver.h Configuration.cpp Configuration.h)
