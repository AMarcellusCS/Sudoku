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
    public: static Configuration solve(Configuration currentConfig){
        queue<Configuration> queue;
        map<string, string> visited;
        int totalConfigs = 1;
        //queue.push(currentConfig);
        //visited.insert(currentConfig.toString(), 0);
        while(!queue.empty()){

        }
    }
};


#endif //SUDOKU_SOLVER_H
