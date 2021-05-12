#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
#include "inputValidation.h"
int main() {
    int column_size = 5;
    int row_size = 5;
    Snake theSnake;
    srand((unsigned) time(0));
    //std::rng(seed);
    //IMPORTANT NOTE, the X values are accessed from .at.().at(this one)
    // and Y is the first .at()
    std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, ' '));
    fillBorders(gameScreen, row_size, column_size);

    theSnake.setHead(row_size / 2, column_size / 2);
    theSnake.addSegment((row_size / 2) + 1, column_size / 2);
    //theSnake.addSegment((row_size / 2) + 2, column_size / 2);
    updateBoard(theSnake, gameScreen);
    generateApple(gameScreen, row_size, column_size);
    updateBoard(theSnake, gameScreen);
    printBoard(gameScreen, row_size, column_size);


    bool gameOn = true;
    int choiceCounter = 0;
    while(gameOn){
        char choice;
        //std::cout << "Make a choice" << std::endl;
        choice = getValidChar("");
        std::cout << std::endl;
        bool checkValid = validateUserInput(choice, theSnake,gameScreen);

        if(checkValid){
            theSnake.updateSnake(choice);
            theSnake.eatApple(gameScreen, choice);
            checkHitBorder(theSnake, gameScreen);
            checkWin(theSnake, row_size, column_size);
            emptyBoard(gameScreen, row_size, column_size);
            fillBorders(gameScreen, row_size, column_size);
            updateBoard(theSnake, gameScreen);
            printBoard(gameScreen, row_size, column_size);
            choiceCounter++;
        }

        if(choiceCounter == 10){
            gameOn  = false;
        }
    }


    return 0;
}
