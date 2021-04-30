//
// Created by Sauvikesh Lal on 4/25/21.
//

#include "theBoard.h"
#include "snakeClass.h"
#include <vector>
#include <iostream>

void fillBoard(std::vector<std::vector<char>>& theBoard, const int& row_size, const int& column_size) {
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
void updateBoard(Snake& theSnake, std::vector<std::vector<char>>& theBoard) {
    for (const auto& element : theSnake.getsnakeVector()) {
        if(element.second == 0){
            theBoard.at(element.first.second).at(element.first.first) = 'H';
        } else {
            theBoard.at(element.first.first).at(element.first.second) = 'S';
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
