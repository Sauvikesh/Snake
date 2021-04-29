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
    std::pair<int, int> getTail();


private:
    std::vector<std::pair<std::pair<int, int>, int>> snakeBodyPositions;
};

#endif //SNAKE_SNAKECLASS_H
