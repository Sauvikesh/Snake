#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
int main() {
    int column_size = 10;
    int row_size = 10;
    Snake theSnake;
    std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, '*'));

    gameScreen.at(0).at(6) = 'V';
    printBoard(gameScreen, row_size, column_size);

    char choice;
    std::cin >> choice;

    clearConsole();

    printBoard(gameScreen, row_size, column_size);

    std::cin >> choice;

    clearConsole();

    printBoard(gameScreen, row_size, column_size);

    return 0;
}
