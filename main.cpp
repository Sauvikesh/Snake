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

    for (int i = 0; i < gameScreen.size(); ++i) {
        for (int j = 0; j < column_size; ++j) {
            std::cout << gameScreen.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    char choice;
    std::cin >> choice;
    gameScreen.at(0).at(1) = '>';
    gameScreen.at(0).at(0) = '/';
    gameScreen.at(1).at(0) = '|';


    for (int n = 0; n < 10; n++){
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

    for (int i = 0; i < gameScreen.size(); ++i) {
        for (int j = 0; j < column_size; ++j) {
            std::cout << gameScreen.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }


    std::cin >> choice;
    gameScreen.at(0).at(2) = '>';
    gameScreen.at(0).at(1) = '-';
    gameScreen.at(0).at(0) = '/';

    for (int n = 0; n < 10; n++){
        printf( "\n\n\n\n\n\n\n\n\n\n" );
    }

    for (int i = 0; i < gameScreen.size(); ++i) {
        for (int j = 0; j < column_size; ++j) {
            std::cout << gameScreen.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
