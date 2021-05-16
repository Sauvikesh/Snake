//
// Created by Sauvikesh Lal on 5/7/21.
//

#ifndef SNAKE_INPUTVALIDATION_H
#define SNAKE_INPUTVALIDATION_H
#include <string>
#include <iostream>
#include <sstream>
#include "snakeClass.h"
#include "theBoard.h"
char getValidChar(const std::string& prompt);
bool StreamOnlyContainsWhiteSpace(std::istream& stream);
bool validateUserInput(char direction, Snake& theSnake, const gameScreen& gameScreen);

#endif //SNAKE_INPUTVALIDATION_H
