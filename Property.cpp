#include "Property.h"

Property::Property() : name(""), cost(0), rent(0), owner("Bank"), isOwned(false) {}

Property::Property(const std::string& n, int c, int r)
    : name(n), cost(c), rent(r), owner("Bank"), isOwned(false) {}

std::string Property::getName() const { return name; }
int Property::getCost() const { return cost; }
int Property::getRent() const { return rent; }
std::string Property::getOwner() const { return owner; }
bool Property::getIsOwned() const { return isOwned; }

void Property::setOwner(const std::string& newOwner) 
{ 
    owner = newOwner; 
    isOwned = true; 
}

void Property::resetOwner() 
{ 
    owner = "Bank"; 
    isOwned = false; 
}

void Property::setIsOwned(const bool owned) 
{ 
    isOwned = owned; 
}