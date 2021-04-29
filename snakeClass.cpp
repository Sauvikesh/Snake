//
// Created by Sauvikesh Lal on 4/26/21.
//
#include <iostream>
#include "snakeClass.h"
#include <utility>

void Snake::setHead(int x, int y) {
    headPosition = std::make_pair(x,y);
}

std::pair<int, int> Snake::getHead() {
    return headPosition;
}

void Snake::setTail(int x, int y) {
    tailPosition = std::make_pair(x,y);
}

std::pair<int, int> Snake::getTail() {
    return tailPosition;
}

void Snake::setLength(int length) {
    snakeLength = length;
}
int Snake::getLength() {
    return snakeLength;
}



