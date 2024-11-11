#pragma once
#include <string>

class Property
{
private:
    std::string name;
    int cost;
    int rent;
    std::string owner;
    bool isOwned;
    
public:
    // Default constructor
    Property();
    
    // Parameter constructor
    Property(const std::string& n, int c, int r);
    
    // Getters & Setters
    std::string getName() const;
    int getCost() const;
    int getRent() const;
    std::string getOwner() const;
    bool getIsOwned() const;
    void setOwner(const std::string& newOwner);
    void resetOwner();
    void setIsOwned(const bool owned);
};