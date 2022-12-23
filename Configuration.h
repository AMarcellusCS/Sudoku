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
    Configuration(string fileName){
        ifstream inputFile;
        inputFile.open(fileName, ios::in);
        if(inputFile)
            cout << "File not found" << endl;
        else{
            string line;
            while(getline(inputFile, line)){
                istringstream iss(line);
                cout << line;
                int x, y, val;
                if(!(iss >> x >> y >> val))
                    break;
                board[x][y] = val;
            }
        }

    }
    string toString(){
        string value = "";
        for(int i = 0; i < (DIM*DIM); i++)
            value += board[i/DIM][i%DIM];
        return value;
    }
    void printBoard() {
        for (int x = 0; x < DIM; x++) {
            for (int y = 0; y < DIM; y++)
                cout << board[x][y];
            cout << " " << endl;
        }
    }
};


#endif //SUDOKU_CONFIGURATION_H
