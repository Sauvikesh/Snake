//
// Created by Sauvikesh Lal on 4/25/21.
//

#include "theBoard.h"
#include <vector>
void createBoard(std::vector<std::vector<char>>& theBoard, int row_size, int column_size) {


    for (int i = 0; i < row_size; ++i) {
        for (int j = 0; j < column_size; ++j) {
            theBoard.at(i).push_back('*');
        }
    }

}
