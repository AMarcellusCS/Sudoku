#include <iostream>
#include "Configuration.h"

int main() {
    Configuration config = Configuration("game-1.txt");
    config.printBoard();
//    printf("Press ENTER key to Continue\n");
//    getchar();
    return 0;
}
