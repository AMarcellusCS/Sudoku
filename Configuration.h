//
// Created by adrian.marcellus on 12/22/2022.
//

#ifndef SUDOKU_CONFIGURATION_H
#define SUDOKU_CONFIGURATION_H

using namespace std;
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <queue>
#include <map>

class Configuration {
private:
    static const int DIM = 9;
    int board[DIM][DIM];
    int xCord;
    int yCord;

    bool verticalCheck();

    bool horizontalCheck();

    bool sectionCheck();

    void copyBoard(int childBoard[DIM][DIM]);

public:
    explicit Configuration();

    explicit Configuration(string fileName);

    explicit Configuration(int x, int y, int value, Configuration* parentConfig);

    string toString();

    void printBoard();

    vector<Configuration> getSuccessors();//std::queue<Configuration> queue, std::map<string, string> map);

    bool isValid();

    bool isGoal();

    void nextCords();
};


#endif //SUDOKU_CONFIGURATION_H
