#pragma once
#include <iostream>
#include "Player.h"
#include "Property.h"
#include "PlayerManager.h"

struct GraphNode;

class Board
{
private:
    GraphNode* head;
    GraphNode* tail;

    GraphNode* createGraphNode(Property* property);

public:
    Board();  // constructor

    // function to initialize the board as a graph
    void initializeBoard();

    // function to display the board status (properties in the graph)
    void displayBoardStatus() const;

    // function to handle property based on player landing
    void handleProperty(Player& player, Property& property);

    // function to move player on the graph (by number of steps)
    void movePlayer(Player& player, int steps);

    // other functions
    GraphNode* getHead() const;
    GraphNode* getTail() const;
    int getSize() const;
    Property& getProperty(int position);
};
