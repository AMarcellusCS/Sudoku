//
// Created by adrian.marcellus on 12/22/2022.
//

#include "Configuration.h"
using namespace std;
#include <string>
#include <iostream>
#include <queue>
#include <set>

namespace std {
    template<>
    struct hash<Configuration>{
        size_t operator()(Configuration& key){
            return stoi(key.toString());
        }
    };
}
// empty configuration constructor
Configuration::Configuration() {
    for (int x = 0; x < DIM; x++)
        for (int y = 0; y < DIM; y++)
            board[x][y] = 0;
    nextCords();
}
// initial configuration constructor to read game from given file
Configuration:: Configuration(string fileName){
    for(int i = 0; i < (DIM*DIM); i++)
        board[i/DIM][i%DIM] = 0;
    ifstream inputFile;
    inputFile.open(fileName, ios::in);
    if(!inputFile.is_open())
        cout << "File not found" << endl;
    else{
        string line;
        while(getline(inputFile, line)){
            istringstream iss(line);
            int x, y, val;
            if(!(iss >> x >> y >> val))
                break;
            board[x][y] = val;
        }
    }
    nextCords();
    inputFile.close();
}
// constructor that copy's a parent config's board into a new config and changes one value.
Configuration::Configuration(int x, int y, int value, Configuration* parentConfig) {
    parentConfig -> copyBoard(this->board);
    this->board[x][y] = value;
    this->xCord = x;
    this->yCord = y;
}
// returns a string of a configs board in order
 string Configuration:: toString(){
    string value;
    for(int i = 0; i < (DIM*DIM); i++)
        value += board[i/DIM][i%DIM];
    return value;
}
// prints out a sudoku board from the board array values
void Configuration:: printBoard() {
    cout << endl;
    for (int x = 0; x < DIM; x++) {
        for (int y = 0; y < DIM; y++) {
            if ((y+1) % SECTION_SIZE == 0 && y != 0 && y != DIM - 1)
                cout << board[x][y] << " | ";
            else
                cout << board[x][y] << ' ';
        }
        cout << endl;
        if ((x+1) % SECTION_SIZE == 0 && x != 0 && x != DIM - 1)
            cout << "---------------------" << endl;
    }
    cout << endl;
}
// returns a vector of only valid neighbors, hence successors
vector<Configuration> Configuration::getSuccessors(){
    vector<Configuration> successors;
    for(int j = 1; j <= 9; j++) {
        successors.emplace_back(xCord, yCord, j, this);
        if(!successors.back().isValid())
            successors.pop_back();
        else {
            successors.back().nextCords();
            //successors.back().printBoard();
        }
    }
    return successors;
}
//checks if the puzzle is solved by checking if any zeros remain on the board from current index
bool Configuration::isGoal() {
    bool goal = true;
    for(int i = (this->xCord*this->yCord); i < (DIM*DIM); i++)
        if(board[i/DIM][i%DIM] == 0)
            return false;
    return goal;
}
// public function that checks if a configuration is valid via 3 private helper functions
bool Configuration::isValid() {
    return verticalCheck() && horizontalCheck() && checkSection();
}
// puts the iterator at the next zero entry on the board
void Configuration::nextCords() {
    for(int i = 0; i < (DIM * DIM); i++)
        if(board[i / DIM][i % DIM] == 0) {
            this->xCord = i / DIM;
            this->yCord = i % DIM;
            break;
        }
}
// copy's a configs board to a neighbors board
void Configuration::copyBoard(int neighborsBoard[DIM][DIM]) {
    for(int i = 0; i < (DIM * DIM); i++)
        neighborsBoard[i / DIM][i % DIM] = board[i / DIM][i % DIM];
}
// checks if a board is valid vertically from current iterator index
bool Configuration::verticalCheck(){
    set<int> seenNumbers;
    for(int i = 0; i < DIM; i++){
        if(!seenNumbers.contains(this->board[i][yCord]))
            seenNumbers.insert(this->board[i][yCord]);
        else if (this->board[i][yCord] != 0) {
            //cout << "X: " << xCord << " Y: " << yCord << " VERT PRUNED FOR VALUE: " << this->board[i][yCord] << endl;
            return false;
        }
    }
    return true;
}
// checks if a board is valid horizontally from current iterator index
bool Configuration::horizontalCheck() {
    set<int> seenNumbers;
    for(int i = 0; i < DIM; i++){
        if(!seenNumbers.contains(this->board[xCord][i]))
            seenNumbers.insert(this->board[xCord][i]);
        else if (this->board[xCord][i] != 0) {
            //cout << "X: " << xCord << " Y: " << yCord << " HORI PRUNED FOR VALUE: " << this->board[xCord][i] << endl;
            return false;
        }
    }
    return true;
}
// checks if a 3x3 section is valid from current iterator index
bool Configuration::checkSection(){
    set<int> seenNumbers;
    for(int x = this->xCord-(this->xCord%SECTION_SIZE); x < this->xCord+(SECTION_SIZE - this->xCord%SECTION_SIZE); x++)
        for(int y = this->yCord-(this->yCord%SECTION_SIZE); y < this->yCord+(SECTION_SIZE - this->yCord%SECTION_SIZE); y++)
            if(!seenNumbers.contains(this->board[x][y]))
                seenNumbers.insert(this->board[x][y]);
            else if (this->board[x][y] != 0) {
                //cout << "X: " << xCord << " Y: " << yCord << " SECTION PRUNED FOR VALUE: " << this->board[x][y] << endl;
                return false;
            }
    return true;
}
//create a config from a string that represents board values
Configuration::Configuration(string stringToConvert, bool nextCord) {
    for(int i = 0; i < (DIM*DIM); i++)
        board[i/DIM][i%DIM] = static_cast<int>(stringToConvert.at(i));
    if(nextCord)
        nextCords();
}



