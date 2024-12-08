#include "PropertyManager.h"

void PropertyManager::addProperty(const Property& property) 
{
  propertyTable[property.getName()] = property;
}

Property* PropertyManager::getProperty(const std::string& name) 
{
    auto it = propertyTable.find(name);
    if (it != propertyTable.end()) {
        return &it->second;
    }
    return nullptr;
}

bool PropertyManager::removeProperty(const std::string& name) 
{
    return propertyTable.erase(name) > 0;
}

bool PropertyManager::hasProperty(const std::string& name) const 
{
    return propertyTable.find(name) != propertyTable.end();
}

void PropertyManager::displayProperties() const 
{
    for (const auto& [name, property] : propertyTable) 
    {
        std::cout << "Property Name: " << name
                  << ", Cost: " << property.getCost()
                  << ", Rent: " << property.getRent()
                  << ", Owned: " << (property.getIsOwned() ? "Yes" : "No")
                  << ", Owner: " << property.getOwner() << std::endl;
    }
}