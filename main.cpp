#include <iostream>
#include "Configuration.h"

int main() {
    Configuration config = Configuration("game-1.txt");
    config.printBoard();
    config.getSuccessors();
    //vector<Configuration> configVector = config.getSuccessors();
    //configVector.begin()->printBoard();
//    for (auto & configs : configVector)
//        configs.printBoard();

//    printf("Press ENTER key to Continue\n");
//    getchar();
    return 0;
}
