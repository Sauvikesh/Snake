#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
int main() {
    int column_size = 6;
    int row_size = 4;
    Snake theSnake;
    std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, ' '));

    fillBoard(gameScreen, row_size, column_size);

    printBoard(gameScreen, row_size, column_size);

    clearConsole();

    return 0;
}
