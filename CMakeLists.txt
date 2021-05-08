cmake_minimum_required(VERSION 3.19)
project(Snake)

set(CMAKE_CXX_STANDARD 14)

add_executable(Snake main.cpp theBoard.cpp theBoard.h snakeClass.cpp snakeClass.h inputValidation.cpp inputValidation.h)