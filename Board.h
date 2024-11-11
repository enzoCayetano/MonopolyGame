#pragma once
#include <iostream>
#include <map>
#include "Player.h"
#include "Property.h"
#include "PlayerManager.h"

class Board
{
private:
    std::map<int, Property> board; // The board with property positions
    
public:
    const std::map<int, Property>& getBoard() const;
    void setBoard(const std::map<int, Property>& newBoard);
    void addProperty(int position, const Property& property);
    Property& getProperty(int position);
    int getSize() const;
    
    void displayBoardStatus() const;

    // Initialize property spaces on the board
    // 40 spaces in total
    void initializeBoard();
    
    // Handle property within Board class
    void handleProperty(Player& player, Property& property);
};