#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
int main() {
    int column_size = 12;
    int row_size = 10;
    Snake theSnake;
    std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, ' '));

    fillBoard(gameScreen, row_size, column_size);
    gameScreen.at(4).at(7) = 'V';
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
