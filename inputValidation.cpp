//
// Created by Sauvikesh Lal on 5/7/21.
//

#include "inputValidation.h"
#include "snakeClass.h"
#include "theBoard.h"
#include <string>
#include <iostream>
#include <sstream>

char getValidChar(const std::string& prompt) {
    std::string lineRead;
    char val;
    bool readSuccessful = false;
    do{
        std::cout << prompt;
        std::getline(std::cin, lineRead); // grab the line
        std::stringstream lineParser(lineRead); //put it into a string stream so we can parse it
        lineParser >> val; //read what we want
        readSuccessful = StreamOnlyContainsWhiteSpace(lineParser); //check that there isn't anything left
    }while(!readSuccessful); //keep asking until they give me what I want
    return val;
}

bool StreamOnlyContainsWhiteSpace(std::istream& stream) {
    char c ='!';
    if(!stream){ //if you can't read from the stream
        return false; //something is wrong with the stream
    }else{
        stream >> c; // attempt to read a nonwhitespace character
        //if the stream is bad it means we failed to read
        //and we should since there shouldn't be anything left
        return !stream;
    }
}

bool validateUserInput(char direction, Snake& theSnake, std::vector<std::vector<char>> gameScreen) {
    std::pair<int,int> headLocation = theSnake.getHead();
    if(direction == 'w') {
        if(gameScreen.at(headLocation.first - 1).at(headLocation.second) == ' ' || gameScreen.at(headLocation.first - 1).at(headLocation.second) == 'A'){
            return true;
        }
    }
    else if(direction == 's') {
        if(gameScreen.at(headLocation.first + 1).at(headLocation.second) == ' ' || gameScreen.at(headLocation.first + 1).at(headLocation.second) == 'A'){
            return true;
        }
    }
    else if(direction == 'a'){
        if(gameScreen.at(headLocation.first).at(headLocation.second - 1) == ' ' || gameScreen.at(headLocation.first).at(headLocation.second - 1) == 'A'){
            return true;
        }
    }
    else if(direction == 'd'){
        if(gameScreen.at(headLocation.first).at(headLocation.second + 1) == ' ' || gameScreen.at(headLocation.first).at(headLocation.second + 1) == 'A'){
            return true;
        }
    }
    else{
        return false;
    }
}