//
// Created by adrian.marcellus on 12/22/2022.
//

#include <unordered_map>
#include "Solver.h"

vector<string> Solver::solve(Configuration currentConfig) {
    queue <Configuration> queue;
    map <string, string> visited;
    Configuration null = Configuration();
    visited.insert(pair<string, string>(currentConfig.toString(), null.toString()));
    while (!queue.empty()) {
        currentConfig = queue.front();
        queue.pop();
        if(currentConfig.isGoal())
            return getPath(visited, currentConfig.toString());
        else {
            vector<Configuration> neighbors = currentConfig.getSuccessors();
            for (auto &config : neighbors)
                if(!visited.contains(config.toString()) && config.isValid()) {
                    config.nextCords();
                    queue.push(config);
                    visited.insert(pair<string, string>(config.toString(), currentConfig.toString()));
                }
        }
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
    return path;
}
