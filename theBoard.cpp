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
    std::vector<std::vector<char>> gameBoard(rows, std::vector<char>(cols, ' '));
}

void fillBorders(std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size) {
    for (int i = 0; i < column_size; i++) {
        theBoard.at(0).at(i) = '*';
    }

    for (int i = 0; i < row_size; i++){
        theBoard.at(i).at(0) = '*';
        theBoard.at(i).at(column_size - 1) = '*';
    }

    for (int i = 0; i < column_size; i++) {
        theBoard.at(row_size - 1).at(i) = '*';
    }
}

void emptyBoard(std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size) {
    for (int i = 0; i < row_size; i++)  {
        for (int j = 0; j < column_size; ++j) {
            if(theBoard.at(i).at(j) == 'A'){
                continue;
            } else{
                theBoard.at(i).at(j) = ' ';
            }
        }
    }
}
void updateBoard(Snake& theSnake, std::vector<std::vector<char>>& theBoard) {
    for(int i = 0; i < theSnake.getsnakeVectorX().size(); i++) {
        if (i == 0) {
            theBoard.at(theSnake.getsnakeVectorX().at(i)).at(theSnake.getsnakeVectorY().at(i)) = 'H';
        } else {
            theBoard.at(theSnake.getsnakeVectorX().at(i)).at(theSnake.getsnakeVectorY().at(i)) = 'S';
        }
    }

}

void printBoard(std::vector<std::vector<char>>& theBoard, int row_size, int column_size) {

    for (int i = 0; i < row_size; i++) {
        for(int j = 0; j < column_size; j++) {
            std::cout << theBoard.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void clearConsole() {
    for (int n = 0; n < 10; n++) {
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}

void generateApple(std::vector<std::vector<char>>& theBoard, int row_size, int column_size) {
    int random_x;
    int random_y;
    while(true){
        random_x = (rand() % (column_size - 1)) + 1;
        random_y = (rand() % (row_size - 1)) + 1;
        //std::cout << random_y << " " << random_x << std::endl;
        if(isspace(theBoard.at(random_y).at(random_x))) {
            break;
        }
    }
    theBoard.at(random_y).at(random_x) = 'A';
}

bool checkApple(std::vector<std::vector<char>>& theBoard, int row_size, int column_size) {
    for (int i = 0; i < row_size; i++) {
        for(int j = 0; j < column_size; j++) {
            if(theBoard.at(i).at(j) == 'A'){
                return true;
            }
        }
    }
    return false;

}

void checkHitBorder(Snake& theSnake, std::vector<std::vector<char>> gameScreen) {
    if(gameScreen.at(theSnake.getHead().first).at(theSnake.getHead().second) == '*'){
        std::cout << "Uh oh, you hit the border" << std::endl;
        std::cout << "Game over :((";
        exit(0);
    }
}

void checkHitSnake(Snake& theSnake, std::vector<std::vector<char>> gameScreen) {
    if(gameScreen.at(theSnake.getHead().first).at(theSnake.getHead().second) == 'S'){
        std::cout << "Uh oh, you hit yourself" << std::endl;
        std::cout << "Game over :((";
        exit(0);
    }
}

void checkWin(Snake& theSnake, int row_size, int col_size) {
    if(theSnake.getsnakeVectorX().size() == ((row_size - 2) * (col_size - 2))){
        std::cout << "You've filled the board!!" << std::endl;
        std::cout << "You win!! :))";
        exit(0);
    }
}
