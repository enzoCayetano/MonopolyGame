#pragma once
#include <list>
#include <queue>
#include <string>
#include "Board.h"
#include "Player.h"

// Forward declare Board and Player
class Board;
class Player;

// Player Manager class
class PlayerManager
{
private:
    std::list<Player> players; // List of players
    std::queue<Player*> turnOrder; // Queue for player turns
    Board* board;
    
public:
    const std::list<Player> getPlayers() const;
    void addPlayer(const std::string& playerName);
    Player* getNextPlayer();
    void displayPlayerStats(const Player& player, const Board& board);
    int calculateCumulativeScore(const Board& board) const;
    int calculateCumulativeScoreRecursive(std::list<Player>::const_iterator current, std::list<Player>::const_iterator end, const Board& board) const;
};