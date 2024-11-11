#pragma once
#include <stack>
#include <vector>
#include <string>
#include <random>
#include <list>
#include <iostream>
#include "Player.h"
#include "ChanceCard.h"
#include "CommunityChestCard.h"

// Deck class
class Deck
{
private:
    std::stack<ChanceCard> chanceDeck; // Stack for chance cards
    std::stack<CommunityChestCard> communityChestDeck; // Stack for community chest cards
    
public:
    void initializeDecks();
    void drawChanceCard(Player& player);
    void drawCommunityChestCard(Player& player);
};