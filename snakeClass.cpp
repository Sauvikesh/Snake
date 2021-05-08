//
// Created by Sauvikesh Lal on 4/26/21.
//
#include <iostream>
#include "snakeClass.h"
#include <utility>

void Snake::setHead(int x, int y) {
    this->snakeBodyPositionsX.push_back(x);
    this->snakeBodyPositionsY.push_back(y);
}

std::pair<int, int> Snake::getHead() {
    auto the_pair = std::make_pair(snakeBodyPositionsX.at(0), snakeBodyPositionsY.at(0));
    return the_pair;
}

void Snake::addSegment(int x, int y) {
    this->snakeBodyPositionsX.push_back(x);
    this->snakeBodyPositionsY.push_back(y);
}

std::vector<int> Snake::getsnakeVectorX() {
    return snakeBodyPositionsX;
}
std::vector<int> Snake::getsnakeVectorY() {
    return snakeBodyPositionsY;
}

std::pair<int, int> Snake::getTail() {
    return snakeBodyPositionsX.at(snakeBodyPositionsX.size() - 1).first;
}





