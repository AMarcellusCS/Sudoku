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
    static const int SECTION_SIZE = 3;
    int board[DIM][DIM];
    int xCord = 0;
    int yCord = 0;

    bool verticalCheck();

    bool horizontalCheck();

    bool checkSection();

    void copyBoard(int neighborsBoard[DIM][DIM]);

    void nextCords();

public:
    explicit Configuration();

    explicit Configuration(string fileName);

    explicit Configuration(int x, int y, int value, Configuration* parentConfig);

    explicit Configuration(string stringToConvert, bool nextCord);

    string toString();

    void printBoard();

    vector<Configuration> getSuccessors();//std::queue<Configuration> queue, std::map<string, string> map);

    bool isValid();

    bool isGoal();
};


#endif //SUDOKU_CONFIGURATION_H
