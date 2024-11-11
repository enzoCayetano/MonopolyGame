#pragma once
#include <string>
#include "Player.h"

class CommunityChestCard
{
public:
    enum class Action {
        DOCTOR_FEES,
        STOCK_SALE,
        GET_OUT_OF_JAIL,
    };
    
private:
    Action action;
    std::string description;
    
public:
    // Constructor
    CommunityChestCard(Action action, const std::string&);
    void applyCard(Player& player) const;
    const std::string& getDescription() const;
};