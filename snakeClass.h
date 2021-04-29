//
// Created by Sauvikesh Lal on 4/26/21.
//

#ifndef SNAKE_SNAKECLASS_H
#define SNAKE_SNAKECLASS_H
class Snake {
public:
    void setHead(int x, int y);
    std::pair<int, int> getHead();

    void setTail(int x, int y);
    std::pair<int, int> getTail();

    void setLength(int length);
    int getLength();
private:
    std::pair<int, int> headPosition;
    std::pair<int, int> tailPosition;
    int snakeLength;
};

#endif //SNAKE_SNAKECLASS_H
