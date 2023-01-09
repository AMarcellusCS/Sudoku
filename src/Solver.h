//
// Created by adrian.marcellus on 12/22/2022.
//

#ifndef SUDOKU_SOLVER_H
#define SUDOKU_SOLVER_H

using namespace std;
#include "Configuration.h"
#include <queue>
#include <map>
#include <list>
#include <string>

class Solver {
public:
    static vector<string> solve(Configuration currentConfig);
};


#endif //SUDOKU_SOLVER_H
