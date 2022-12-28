//
// Created by adrian.marcellus on 12/22/2022.
//

#include <unordered_map>
#include "Solver.h"

vector<string> Solver::solve(Configuration currentConfig) {
    queue <Configuration> queue;
    map <string, string> visited;
    Configuration null = Configuration();
    currentConfig.getNeighbors(queue, visited); // switch to addall neighbors
    visited.insert(pair<string, string>(currentConfig.toString(), null.toString()));
    while (!queue.empty()) {
        currentConfig = queue.front();
        queue.pop();
        if(currentConfig.isSolution())
            return getPath(visited, currentConfig.toString());
        else
            currentConfig.getNeighbors(queue, visited);
    }
    vector<string> returnNoSolution;
    return returnNoSolution;
}

vector<string> Solver::getPath(map<string, string> visited, string solution) {
    vector<string> path;
    string current = solution;
    while(visited[current].compare(Configuration().toString()) != 0) {
        path.push_back(current);
        current = visited[path.back()];
    }

}
