#include <iostream>
#include "Configuration.h"
#include "Solver.h"

int main() {
    Configuration config = Configuration("game-files/game-1.txt");
    vector<string> path = Solver::solve(config);
    Configuration(path.back(), false).printBoard();
    Configuration(path.front(), false).printBoard();
    return 0;
}
