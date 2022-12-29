#include <iostream>
#include "Configuration.h"
#include "Solver.h"

int main() {
    Configuration config = Configuration("game-1.txt");
    vector<string> path = Solver::solve(config);
    Configuration(path.front(), false).printBoard();
    Configuration(path.back(), false).printBoard();
    return 0;
}
