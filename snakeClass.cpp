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

std::pair<int, int> Snake::getHead() const{
    auto the_pair = std::make_pair(snakeBodyPositionsX.at(0), snakeBodyPositionsY.at(0));
    return the_pair;
}

void Snake::addSegment(int x, int y) {
    this->snakeBodyPositionsX.push_back(x);
    this->snakeBodyPositionsY.push_back(y);
}

void Snake::updateSnake(char direction) {
    std::pair<int,int> lastPosition = this->getHead();
    std::pair<int,int> currentPosition;
    if(direction == 'w') {
        snakeBodyPositionsX.at(0) -= 1;
    }
    else if(direction == 's'){
        snakeBodyPositionsX.at(0) += 1;
    }
    else if(direction == 'a'){
        snakeBodyPositionsY.at(0) -= 1;
    }
    else if(direction == 'd'){
        snakeBodyPositionsY.at(0) += 1;
    }

    for (int i = 1; i < snakeBodyPositionsX.size(); i ++){
        currentPosition = std::make_pair(snakeBodyPositionsX.at(i),snakeBodyPositionsY.at(i));
        snakeBodyPositionsX.at(i) = lastPosition.first;
        snakeBodyPositionsY.at(i) = lastPosition.second;
        lastPosition = currentPosition;
    }
}

std::vector<int> Snake::getsnakeVectorX() const {
    return snakeBodyPositionsX;
}
std::vector<int> Snake::getsnakeVectorY() const {
    return snakeBodyPositionsY;
}

std::pair<int, int> Snake::getTail() const {
    auto the_pair = std::make_pair(snakeBodyPositionsX.at(snakeBodyPositionsX.size() - 1), snakeBodyPositionsY.at(snakeBodyPositionsX.size() - 1));
    return the_pair;

}


void Snake::eatApple(const std::vector<std::vector<char>>& gameScreen, const std::pair<int ,int>& tailCoords) {
    if(gameScreen.at(snakeBodyPositionsX.at(0)).at(snakeBodyPositionsY.at(0)) == 'A'){
        this->addSegment(tailCoords.first, tailCoords.second);
    }
}





