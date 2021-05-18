//
// Created by Sauvikesh Lal on 4/26/21.
//

#ifndef SNAKE_SNAKECLASS_H
#define SNAKE_SNAKECLASS_H
#include <vector>
#include <utility>
class Snake {
public:
    void setHead(int x, int y);
    std::pair<int, int> getHead();
    void addSegment(int x, int y);
    void updateSnake(char direction);
    std::vector<int> getsnakeVectorX();
    std::vector<int> getsnakeVectorY();
    std::pair<int, int> getTail();
    std::pair<int, int> findDifferencetoAddSegment();
    void eatApple(const std::vector<std::vector<char>>& gameScreen, const std::pair<int ,int>& tailCoords);


private:
    std::vector<int> snakeBodyPositionsX;
    std::vector<int> snakeBodyPositionsY;
};

#endif //SNAKE_SNAKECLASS_H
