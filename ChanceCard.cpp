#include "ChanceCard.h"
#include <iostream>

ChanceCard::ChanceCard(Action action, const std::string& description) : action(action), description(description) {}

void ChanceCard::applyCard(Player& player) const 
{
    switch (action) 
    {
        case Action::MOVE_TO_GO:
            player.setPosition(0);  // Move to Go space
            player.addMoney(200);   // Collect $200
            std::cout << player.getName() << " advanced to Go and collected $200!" << std::endl;
            break;
        case Action::GO_TO_JAIL:
            player.setPosition(10); // Move to Jail
            std::cout << player.getName() << " goes to Jail!" << std::endl;
            break;
        case Action::PAY_TAX:
            player.subtractMoney(15); // Pay poor tax
            std::cout << player.getName() << " paid $15 poor tax." << std::endl;
            break;
        case Action::COLLECT_MONEY:
            player.addMoney(100);
            std::cout << player.getName() << " collected $100 from the bank!" << std::endl;
            break;
    }
}

const std::string& ChanceCard::getDescription() const {
    return description;
}