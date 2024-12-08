#pragma once
#include "Property.h"

class PropertyNode 
{
public:
    Property property;
    PropertyNode* left;
    PropertyNode* right;

    PropertyNode(const Property& prop)
        : property(prop), left(nullptr), right(nullptr) {}
};
