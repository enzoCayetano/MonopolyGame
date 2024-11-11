#include <ctime>
#include "MonopolyGame.h"

int main()
{
    // for randomness
    std::srand(static_cast<unsigned>(std::time(0)));
    
    MonopolyGame game;
    game.playGame(50);
    
    return 0;
}   