#pragma once
#include "Board.h"
#include "Deck.h"
#include "PlayerManager.h"

// MonopolyGame
class MonopolyGame 
{
private:
    std::queue<Player*> turnOrder;
    PlayerManager playerManager;
    Board board;
    Deck deck;
    bool gameOver;

public:
    MonopolyGame();
    
    void setupPlayers();
    
    void startGame(int numTurns);
    
    // game loop
    void playGame(int numTurns);
    
    // Take turn
    void takeTurn(Player& player);
    
    // roll the dice
    int rollDice();
    
    // Present options to the player
    void presentPlayerOptions(Player& player);
};