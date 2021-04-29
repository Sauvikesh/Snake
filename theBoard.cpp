//
// Created by Sauvikesh Lal on 4/25/21.
//

#include "theBoard.h"
#include <vector>
#include <iostream>
void createBoard(std::vector<std::vector<char>>& theBoard, int row_size, int column_size) {

    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < column_size; ++j) {
            theBoard.at(i).push_back('*');
        }
    }
}

void printBoard(std::vector<std::vector<char>>& theBoard, int row_size, int column_size) {
    for (int i = 0; i < theBoard.size(); ++i) {
        for (int j = 0; j < column_size; ++j) {
            std::cout << theBoard.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }
}

void clearConsole() {
    for (int n = 0; n < 10; n++) {
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }
}
