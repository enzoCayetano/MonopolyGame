#include <iostream>
#include "PlayerManager.h"

const std::list<Player> PlayerManager::getPlayers() const { return players; }

void PlayerManager::addPlayer(const std::string& playerName) 
{
    players.emplace_back(playerName, 1500, 0);
    turnOrder.push(&players.back());
}

Player* PlayerManager::getNextPlayer()
{
    Player* nextPlayer = turnOrder.front();
    turnOrder.pop();
    turnOrder.push(nextPlayer);
    return nextPlayer;
}

void PlayerManager::displayPlayerStats(const Player& player, const Board& board)
{
    std::cout << std::endl;
    std::cout << "Player: " << player.getName() << std::endl;
    std::cout << "Money: $" << player.getMoney() << std::endl;
    std::cout << "Position: " << player.getPosition() << std::endl; // Board position
    std::cout << "Properties Owned: ";

    if (player.getProperties().empty()) 
    {
        std::cout << "None" << std::endl;
    } 
    else 
    {
        for (const auto& property : player.getProperties()) 
        {
            std::cout << property << " ";
        }
        std::cout << std::endl;
    }

    int totalAssets = player.getMoney();
    for (const auto& propertyName : player.getProperties()) 
    {
        auto it = std::find_if(board.getBoard().begin(), board.getBoard().end(),
            [&propertyName](const auto& pair) { return pair.second.getName() == propertyName; });
        if (it != board.getBoard().end()) 
        {
            totalAssets += it->second.getCost(); // Add property cost to total
        }
    }

    std::cout << "Total Assets: $" << totalAssets << std::endl;
    std::cout << "Number of Properties Owned: " << player.getProperties().size() << std::endl;
}

int PlayerManager::calculateCumulativeScoreRecursive(std::list<Player>::const_iterator current, std::list<Player>::const_iterator end, const Board& board) const
{
    if (current == end)
        return 0;

    int playerScore = current->getMoney();

    // Calculate property value contribution
    for (const auto& propertyName : current->getProperties())
    {
        auto it = std::find_if(board.getBoard().begin(), board.getBoard().end(),
            [&propertyName](const auto& pair) { return pair.second.getName() == propertyName; });
        if (it != board.getBoard().end())
        {
            playerScore += it->second.getCost(); // Add property cost to player's score
        }
    }

    // Recursive call to process the next player
    return playerScore + calculateCumulativeScoreRecursive(std::next(current), end, board);
}

int PlayerManager::calculateCumulativeScore(const Board& board) const
{
    auto it = players.begin();
    return calculateCumulativeScoreRecursive(it, players.end(), board);
}