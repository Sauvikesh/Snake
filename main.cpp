#include <iostream>
#include <vector>
#include "theBoard.h"
int main() {
    std::vector<std::vector<char>> gameScreen;

    int column_size = 10;
    int row_size = 10;
    createBoard(gameScreen, row_size, column_size);

    for (int i = 0; i < gameScreen.size(); ++i) {
        for (int j = 0; j < column_size; ++j) {
            gameScreen.at(i).push_back('*');
        }
    }

    gameScreen.at(5).at(5) = '^';
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

    for (int i = 0; i < gameScreen.size(); ++i) {
        for (int j = 0; j < column_size; ++j) {
            std::cout << gameScreen.at(i).at(j) << ' ';
        }
        std::cout << std::endl;
    }

    return 0;
}
