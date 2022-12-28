//
// Created by adrian.marcellus on 12/22/2022.
//

#include <unordered_map>
#include "Solver.h"

Configuration Solver::solve(Configuration currentConfig) {
    queue <Configuration> queue;
    map <Configuration, Configuration> visited;
    Configuration null = Configuration();
    int totalConfigs = 1;
    queue.push(currentConfig); // switch to addall neighbors
    visited.insert(pair<Configuration, Configuration>(currentConfig, null));
    while (!queue.empty()) {
    }
}