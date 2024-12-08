#pragma once
#include <iostream>
#include "Property.h"

class PropertyManager
{
private:
  std::unordered_map<std::string, Property> propertyTable;

public:
  void addProperty(const Property& property);
  Property* getProperty(const std::string& name);
  bool removeProperty(const std::string& name);
  bool hasProperty(const std::string& name) const;
  void displayProperties() const;
};