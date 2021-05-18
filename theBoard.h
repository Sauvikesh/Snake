//
// Created by Sauvikesh Lal on 4/25/21.
//
#include <vector>
#include "snakeClass.h"
#ifndef SNAKE_THEBOARD_H
#define SNAKE_THEBOARD_H

class gameScreen{
public:
    // constructor
    gameScreen(int rows, int cols);

    std::vector<std::vector<char>> getGameBoard() const;
    void fillBorders();
    void emptyBoard();
    void updateBoard(Snake& theSnake);
    void printBoard();
    void generateApple();
    bool checkApple() const;
    void checkHitBorder(Snake& theSnake) const;
    void checkHitSnake(Snake& theSnake) const;
    void checkWin(Snake& theSnake) const;
    void clearConsole() const;

private:
    std::vector<std::vector<char>> gameBoard;
    int rows;
    int cols;
};


#endif //SNAKE_THEBOARD_H
