//
// Created by Sauvikesh Lal on 4/25/21.
//

#include "theBoard.h"
#include "snakeClass.h"
#include <vector>
#include <iostream>
#include <cstdlib>
#include <time.h>

gameScreen::gameScreen(int rows, int cols) : rows(rows), cols(cols) {
    std::vector<std::vector<char>> gameBoardTemp(rows, std::vector<char>(cols, ' '));
    this->gameBoard = gameBoardTemp;
}

std::vector<std::vector<char>> gameScreen::getGameBoard() const{
    return this->gameBoard;
}

void gameScreen::fillBorders() {
    for (int i = 0; i < this->cols; i++) {
        this->gameBoard.at(0).at(i) = '*';
    }

    for (int i = 0; i < this->rows; i++){
        this->gameBoard.at(i).at(0) = '*';
        this->gameBoard.at(i).at(this->cols - 1) = '*';
    }

    for (int i = 0; i < this->cols; i++) {
        this->gameBoard.at(this->rows - 1).at(i) = '*';
    }
}

void gameScreen::emptyBoard() {
    for (int i = 0; i < this->rows; i++)  {
        for (int j = 0; j < this->cols; ++j) {
            if(this->gameBoard.at(i).at(j) == 'A'){
                continue;
            } else{
                this->gameBoard.at(i).at(j) = ' ';
            }
        }
    }
}
void gameScreen::updateBoard(Snake& theSnake) {
    for(int i = 0; i < theSnake.getsnakeVectorX().size(); i++) {
        if (i == 0) {
            this->gameBoard.at(theSnake.getsnakeVectorX().at(i)).at(theSnake.getsnakeVectorY().at(i)) = 'H';
        } else {
            this->gameBoard.at(theSnake.getsnakeVectorX().at(i)).at(theSnake.getsnakeVectorY().at(i)) = 'S';
        }
    }

}

void gameScreen::printBoard() {

    for (int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            std::cout << this->gameBoard.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void gameScreen::clearConsole() const{
    for (int n = 0; n < 10; n++) {
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}

void gameScreen::generateApple() {
    int random_x;
    int random_y;
    while(true){
        random_x = (rand() % (this->cols - 1)) + 1;
        random_y = (rand() % (this->rows - 1)) + 1;
        if(isspace(this->gameBoard.at(random_y).at(random_x))) {
            break;
        }
    }
    this->gameBoard.at(random_y).at(random_x) = 'A';
}

bool gameScreen::checkApple() const{
    for (int i = 0; i < this->rows; i++) {
        for(int j = 0; j < this->cols; j++) {
            if(this->gameBoard.at(i).at(j) == 'A') {
                return true;
            }
        }
    }
    return false;
}

void gameScreen::checkHitBorder(Snake& theSnake) const{
    if (this->gameBoard.at(theSnake.getHead().first).at(theSnake.getHead().second) == '*') {
        std::cout << "Uh oh, you hit the border" << std::endl;
        std::cout << "Game over :((";
        exit(0);
    }
}

void gameScreen::checkHitSnake(Snake& theSnake) const{
    if(this->gameBoard.at(theSnake.getHead().first).at(theSnake.getHead().second) == 'S'){
        std::cout << "Uh oh, you hit yourself" << std::endl;
        std::cout << "Game over :((";
        exit(0);
    }
}

void gameScreen::checkWin(Snake& theSnake) const{
    if(theSnake.getsnakeVectorX().size() == ((this->rows - 2) * (this->cols - 2))){
        std::cout << "You've filled the board!!" << std::endl;
        std::cout << "You win!! :))";
        exit(0);
    }
}
