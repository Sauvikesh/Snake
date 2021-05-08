#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
int main() {
    int column_size = 11;
    int row_size = 10;
    Snake theSnake;
    //IMPORTANT NOTE, the X values are accessed from .at.().at(this one)
    // and Y is the first .at()
    std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, ' '));
    fillBorders(gameScreen, row_size, column_size);

    theSnake.setHead(row_size / 2, column_size / 2);
    theSnake.addSegment((row_size / 2) + 1, column_size / 2);
    theSnake.addSegment((row_size / 2) + 2, column_size / 2);

    updateBoard(theSnake, gameScreen);
    printBoard(gameScreen, row_size, column_size);

    char choice;
    std::cout << "Make a choice" << std::endl;

    std::cin >> choice;

    theSnake.updateSnake(choice);


    emptyBoard(gameScreen, row_size, column_size);
    fillBorders(gameScreen, row_size, column_size);
    updateBoard(theSnake, gameScreen);
    printBoard(gameScreen, row_size, column_size);

    //clearConsole();

    return 0;
}
