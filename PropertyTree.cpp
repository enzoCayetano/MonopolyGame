#pragma once
#include "PropertyNode.h"

class PropertyTree 
{
private:
    PropertyNode* root;

    PropertyNode* insert(PropertyNode* node, const Property& property, bool byCost) 
    {
        if (node == nullptr) {
            return new PropertyNode(property);
        }

        if (byCost) 
        {
            if (property.getCost() < node->property.getCost()) 
            {
                node->left = insert(node->left, property, byCost);
            } 
            else 
            {
                node->right = insert(node->right, property, byCost);
            }
        } 
        else 
        {
            if (property.getRent() < node->property.getRent()) 
            {
                node->left = insert(node->left, property, byCost);
            } 
            else 
            {
                node->right = insert(node->right, property, byCost);
            }
        }

        return node;
    }

    Property* lookup(PropertyNode* node, int value, bool byCost) const 
    {
        if (node == nullptr)
            return nullptr;

        if (byCost) 
        {
            if (value == node->property.getCost()) 
            {
                return &(node->property);
            } 
            else if (value < node->property.getCost()) 
            {
                return lookup(node->left, value, byCost);
            } 
            else 
            {
                return lookup(node->right, value, byCost);
            }
        } 
        else 
        {
            if (value == node->property.getRent()) 
            {
                return &(node->property);
            } 
            else if (value < node->property.getRent()) 
            {
                return lookup(node->left, value, byCost);
            } 
            else 
            {
                return lookup(node->right, value, byCost);
            }
        }
    }

    void destroyTree(PropertyNode* node) 
    {
        if (node != nullptr) 
        {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    PropertyTree() : root(nullptr) {}

    ~PropertyTree() 
    {
        destroyTree(root);
    }

    void insert(const Property& property, bool byCost = true) 
    {
        root = insert(root, property, byCost);
    }

    Property* lookup(int value, bool byCost = true) const 
    {
        return lookup(root, value, byCost);
    }
};
