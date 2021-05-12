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


std::vector<int> Snake::getsnakeVectorX() {
    return snakeBodyPositionsX;
}
std::vector<int> Snake::getsnakeVectorY() {
    return snakeBodyPositionsY;
}

std::pair<int, int> Snake::getTail() {

    auto the_pair = std::make_pair(snakeBodyPositionsX.at(snakeBodyPositionsX.size() - 1), snakeBodyPositionsY.at(snakeBodyPositionsX.size() - 1));
    return the_pair;

}

void Snake::eatApple(std::vector<std::vector<char>>& gameScreen, const char& direction){
    if(gameScreen.at(snakeBodyPositionsX.at(0)).at(snakeBodyPositionsY.at(0)) == 'A'){
        switch (direction) {
            case 'w':
                this->addSegment(this->getTail().first + 1, this->getTail().second);
                break;
            case 's':
                this->addSegment(this->getTail().first - 1, this->getTail().second);
                break;
            case 'a':
                this->addSegment(this->getTail().first, this->getTail().second + 1);
                break;
            case 'd':
                this->addSegment(this->getTail().first, this->getTail().second - 1);
                break;
        }
    }
}





