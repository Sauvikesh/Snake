//
// Created by Sauvikesh Lal on 4/26/21.
//
#include <iostream>
#include "snakeClass.h"
#include <utility>

void Snake::setHead(int x, int y) {
    std::pair<int, int> xyCords = std::make_pair(x,y);
    snakeBodyPositions.emplace_back(xyCords, 0);
    //headPosition = std::make_pair(x,y);
}

std::pair<int, int> Snake::getHead() {
    return snakeBodyPositions.at(0).first;
}

void Snake::addSegment(int x, int y) {
    std::pair<int, int> xyCords = std::make_pair(x,y);
    snakeBodyPositions.emplace_back(xyCords, snakeBodyPositions.size());
}

std::pair<int, int> Snake::getTail() {
    return snakeBodyPositions.at(snakeBodyPositions.size() - 1).first;
}





