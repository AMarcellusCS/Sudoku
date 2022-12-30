#include <iostream>
#include "Configuration.h"
#include "Solver.h"

int main() {
    Configuration config = Configuration("game-1.txt");
    vector<string> path = Solver::solve(config);
    Configuration(path.front(), false).printBoard();
    Configuration(path.back(), false).printBoard();
//    vector<Configuration> neighbors = config.getSuccessors().front().getSuccessors();
//    for (auto &configs : neighbors){
//        configs.nextCords();
//        configs.printBoard();
//    }
    return 0;
}
