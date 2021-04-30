#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
int main() {
    int column_size = 15;
    int row_size = 10;
    Snake theSnake;
    theSnake.setHead(6, 6);
    theSnake.addSegment(6,5);
    //IMPORTANT NOTE, the X values are access from .at.().at(this one)
    // and Y is the first .at()
    std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, ' '));

    fillBoard(gameScreen, row_size, column_size);
    updateBoard(theSnake, gameScreen, row_size, column_size);

    printBoard(gameScreen, row_size, column_size);

    clearConsole();

    return 0;
}
