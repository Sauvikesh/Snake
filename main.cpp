#include <iostream>
#include <vector>
#include "theBoard.h"
#include "snakeClass.h"
#include "inputValidation.h"
#pragma clang diagnostic push
#pragma ide diagnostic ignored "EndlessLoop"
int main() {
    int column_size = 8;
    int row_size = 8;
    Snake theSnake;
    srand(time(NULL));
    gameScreen gameScreen1(row_size, column_size);
    //std::vector<std::vector<char>> gameScreen(row_size, std::vector<char>(column_size, ' '));
    gameScreen1.fillBorders();

    theSnake.setHead(row_size / 2, column_size / 2);
    theSnake.addSegment((row_size / 2) + 1, column_size / 2);
    //theSnake.addSegment((row_size / 2) + 2, column_size / 2);
    gameScreen1.updateBoard(theSnake);
    gameScreen1.generateApple();
    gameScreen1.updateBoard(theSnake);
    gameScreen1.printBoard();


    bool gameOn = true;
    int choiceCounter = 0;
    while(gameOn){

        // checks if the snake has eaten the apple and generates new apple
        if(!gameScreen1.checkApple()) {
            gameScreen1.generateApple();
            gameScreen1.updateBoard(theSnake);
            gameScreen1.clearConsole();
            gameScreen1.printBoard();
        }

        char choice;
        choice = getValidChar("");
        std::cout << std::endl;
        bool checkValid = validateUserInput(choice, theSnake, gameScreen1);

        if(checkValid){
            std::pair<int, int> tailCoords = theSnake.getTail();
            theSnake.updateSnake(choice);
            theSnake.eatApple(gameScreen1.getGameBoard(), tailCoords);
            gameScreen1.checkHitBorder(theSnake);
            gameScreen1.checkHitSnake(theSnake);
            gameScreen1.checkWin(theSnake);
            gameScreen1.emptyBoard();
            gameScreen1.fillBorders();
            gameScreen1.updateBoard(theSnake);
            gameScreen1.clearConsole();
            gameScreen1.printBoard();
            choiceCounter++;
        }

    }


    //return 0;
}
