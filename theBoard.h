//
// Created by Sauvikesh Lal on 4/25/21.
//
#include <vector>
#include "snakeClass.h"
#ifndef SNAKE_THEBOARD_H
#define SNAKE_THEBOARD_H

void fillBorders(std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size);
void emptyBoard(std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size);
void updateBoard(Snake& theSnake, std::vector<std::vector<char>>& theBoard);
void printBoard(std::vector<std::vector<char>>& theBoard, int row_size, int column_size);
void generateApple(std::vector<std::vector<char>>& theBoard, int row_size, int column_size);
bool checkApple(std::vector<std::vector<char>>& theBoard, int row_size, int column_size);
void checkHitBorder(Snake& theSnake, std::vector<std::vector<char>> gameScreen);
void checkHitSnake(Snake& theSnake, std::vector<std::vector<char>> gameScreen);
void checkWin(Snake& theSnake, int row_size, int col_size);
void clearConsole();

#endif //SNAKE_THEBOARD_H
