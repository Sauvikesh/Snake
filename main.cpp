#include <iostream>
#include <vector>
#include "theBoard.h"
int main() {
    int column_size = 10;
    int row_size = 10;
    std::vector<std::vector<char>> gameScreen(10);
    createBoard(gameScreen, row_size, column_size);


    gameScreen.at(0).at(0) = '^';
    gameScreen.at(1).at(0) = '|';
    gameScreen.at(2).at(0) = '|';

    printBoard(gameScreen, row_size, column_size);

    char choice;
    std::cin >> choice;
    gameScreen.at(0).at(1) = '>';
    gameScreen.at(0).at(0) = '/';
    gameScreen.at(1).at(0) = '|';


    for (int n = 0; n < 10; n++){
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

    printBoard(gameScreen, row_size, column_size);


    std::cin >> choice;
    gameScreen.at(0).at(2) = '>';
    gameScreen.at(0).at(1) = '-';
    gameScreen.at(0).at(0) = '/';

    for (int n = 0; n < 10; n++){
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

    printBoard(gameScreen, row_size, column_size);

    return 0;
}
