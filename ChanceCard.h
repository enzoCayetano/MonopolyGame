#pragma once
#include <string>
#include "Player.h"

class ChanceCard
{
public:
    enum class Action {
        MOVE_TO_GO,
        PAY_TAX,
        COLLECT_MONEY,
        GO_TO_JAIL,
    };
    
private:
    Action action;
    std::string description;
    
public:
    // Constructor
    ChanceCard(Action action, const std::string&);
    void applyCard(Player& player) const;
    const std::string& getDescription() const;
};