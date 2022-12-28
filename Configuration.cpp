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

namespace std {
    template<>
    struct hash<Configuration>{
        size_t operator()(Configuration& key){
            return stoi(key.toString());
        }
    };
}

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
    inputFile.close();
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

void Configuration::getNeighbors(std::queue<Configuration> queue, std::map<string, string> map) {
    int x;
    int y;
    for(int i = 0; i < (DIM * DIM); i++)
        if(board[i / DIM][i % DIM] == 0) {
            x = i / DIM;
            y = y % DIM;
        }

}

bool Configuration::isSolution() {
    return false;
}
