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
    return verticalCheck() && horizontalCheck() && sectionCheck();
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

bool Configuration::verticalCheck() {
    return false;
}

bool Configuration::horizontalCheck() {
    return false;
}

bool Configuration::sectionCheck() {
    return false;
}



