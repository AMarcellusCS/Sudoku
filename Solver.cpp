//
// Created by adrian.marcellus on 12/22/2022.
//

#include <unordered_map>
#include "Solver.h"
#include "Configuration.h"

vector<string> Solver::solve(Configuration currentConfig) {
    queue <Configuration> queue;
    map <string, string> visited;
    Configuration null = Configuration();
    visited.insert(pair<string, string>(currentConfig.toString(), null.toString()));
    vector<Configuration> initialSuccessors = currentConfig.getSuccessors();
    for (int i = 0; i < initialSuccessors.size(); i++) {
        queue.push(initialSuccessors.at(i));
    }
    long totalConfigs = 1 + queue.size();
    cout << "TOTAL CONFIGS: " << totalConfigs << endl;
    while (!queue.empty()) {
        currentConfig = queue.front();
        queue.pop();
        if(currentConfig.isGoal())
            return getPath(visited, currentConfig.toString());
        else {
            vector<Configuration> neighbors = currentConfig.getSuccessors();
            totalConfigs += neighbors.size();
            cout << "TOTAL CONFIGS: " << totalConfigs << endl;
            cout << "UNIQUE CONFIGS: " << visited.size() << endl;
            for (auto &config : neighbors) {
                if (!visited.contains(config.toString())) {
                    queue.push(config);
                    visited.insert(pair<string, string>(config.toString(), currentConfig.toString()));
                }
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
