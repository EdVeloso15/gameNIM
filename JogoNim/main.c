#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include "gamecontroller.h"

int main()
{
    renderGame();
    confGame();
    loadingGame();
    startGame();
    gameOver();
    return 0;
}
