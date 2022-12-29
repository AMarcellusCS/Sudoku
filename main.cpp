#include <iostream>
#include "Configuration.h"
#include "Solver.h"

int main() {
    Configuration config = Configuration("game-1.txt");
    Solver.solve(config);
    return 0;
}
