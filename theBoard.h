//
// Created by Sauvikesh Lal on 4/25/21.
//
#include <vector>
#include "snakeClass.h"
#ifndef SNAKE_THEBOARD_H
#define SNAKE_THEBOARD_H

void fillBoard(std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size);
void updateBoard(const Snake& theSnake, std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size);
void printBoard(std::vector<std::vector<char>>& theBoard, int row_size, int column_size);
void clearConsole();

#endif //SNAKE_THEBOARD_H
