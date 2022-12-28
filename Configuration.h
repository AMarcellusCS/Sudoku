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

class Configuration {
private:
    static const int DIM = 9;
    int board[DIM][DIM];
public:
    explicit Configuration();
    explicit Configuration(string fileName);
    string toString();
    void printBoard();
};


#endif //SUDOKU_CONFIGURATION_H
