//
// Created by adrian.marcellus on 12/22/2022.
//

#include "Configuration.h"
using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>
#include <algorithm>
#include <set>

namespace std {
    template<>
    struct hash<Configuration>{
        size_t operator()(Configuration& key){
            return stoi(key.toString());
        }
    };
}
// this is a gross use, another way to check if at root of visited.
Configuration::Configuration() {
    for (int x = 0; x < DIM; x++)
        for (int y = 0; y < DIM; y++)
            board[x][y] = 0;
}

Configuration:: Configuration(string fileName){
    for (int x = 0; x < DIM; x++)
        for (int y = 0; y < DIM; y++)
            board[x][y] = 0;
    ifstream inputFile;
    inputFile.open(fileName, ios::in);
    if(!inputFile.is_open())
        cout << "File not found" << endl;
    else{
        string line;
        while(getline(inputFile, line)){
            istringstream iss(line);
            cout << line << endl;
            int x, y, val;
            if(!(iss >> x >> y >> val))
                break;
            board[x][y] = val;
        }
    }
    this->nextCords();
    inputFile.close();
}
Configuration::Configuration(int x, int y, int value, Configuration* parentConfig) {
    parentConfig -> copyBoard(this->board);
    this->board[x][y] = value;
    this->nextCords();
}
 string Configuration:: toString(){
    string value;
    for(int i = 0; i < (DIM*DIM); i++)
        value += board[i/DIM][i%DIM];
    return value;
}

void Configuration:: printBoard() {
    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++)
            cout << board[x][y] << ' ';
        cout << endl;
    }
}

vector<Configuration> Configuration::getSuccessors(){//std::queue<Configuration> queue, std::map<string, string> map) {
    vector<Configuration> successors;
    for(int j = 1; j <= 9; j++) {
        Configuration newConfig = Configuration(this->xCord, this->yCord, j, this);
        successors.push_back(newConfig);
    }
    return successors;
}

bool Configuration::isGoal() {
    return this->xCord == DIM-1 && this->yCord == DIM-1;
}

bool Configuration::isValid() {
    return verticalCheck() && horizontalCheck() && sectionChecker();
}

void Configuration::nextCords() {
    for(int i = 0; i < (DIM * DIM); i++)
        if(board[i / DIM][i % DIM] == 0) {
            this->xCord = i / DIM;
            this->yCord = i % DIM;
            break;
        }
}

void Configuration::copyBoard(int childBoard[DIM][DIM]) {
    for(int i = 0; i < (DIM * DIM); i++)
        childBoard[i / DIM][i % DIM] = board[i / DIM][i % DIM];
}

bool Configuration::verticalCheck(){
    set<int> seenNumbers;
    for(int i = 0; i < DIM; i++){
        if(!seenNumbers.contains(this->board[i][yCord]))
            seenNumbers.insert(this->board[i][yCord]);
        else if (this->board[i][yCord] != 0)
            return false;
    }
    return true;
}

bool Configuration::horizontalCheck() {
    set<int> seenNumbers;
    for(int i = 0; i < DIM; i++){
        if(!seenNumbers.contains(this->board[xCord][i]))
            seenNumbers.insert(this->board[xCord][i]);
        else if (this->board[xCord][i] != 0)
            return false;
    }
    return true;
}

bool Configuration::checkSection(int startX, int endX, int startY, int endY){
    set<int> seenNumbers;
    for(int x = startX; x < endX; x++)
        for(int y = startY; y < endY; y++)
            if(!seenNumbers.contains(this->board[x][y]))
                seenNumbers.insert(this->board[x][y]);
            else if (this->board[x][y] != 0)
                return false;
    return true;
}

bool Configuration::sectionChecker() {
    int dimensions = DIM/3;
    for(int x = 0; x < dimensions; x++)
        for(int y = 0; y < dimensions; y++)
            if(!checkSection(x*MINIMUM_SECTION_SIZE,x*MINIMUM_SECTION_SIZE+3,
                            y*MINIMUM_SECTION_SIZE,y*MINIMUM_SECTION_SIZE+3))
                return false;
    return true;
}



