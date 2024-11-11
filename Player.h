#pragma once
#include <string>
#include <set>

// Player class
class Player
{
private:
    std::string name;
    int money;
    int position;
    std::set<std::string> properties; // Store owned properties
    
public:
    // Constructor
    Player(const std::string& playerName, int startingMoney, int startPosition);
    
    // Getters
    std::string getName() const;
    int getMoney() const;
    int getPosition() const;
    
    // Setters
    void subtractMoney(int amount);
    void addMoney(int amount);
    void setPosition(int newPos);
    
    // Property settings
    std::set<std::string> getProperties() const;
    void addProperty(const std::string& propertyName);
    void removeProperty(const std::string& propertyName);
};