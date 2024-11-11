#include "CommunityChestCard.h"
#include <iostream>

CommunityChestCard::CommunityChestCard(Action action, const std::string& description) : action(action), description(description) {}

void CommunityChestCard::applyCard(Player& player) const 
{
    switch (action) 
    {
        case Action::DOCTOR_FEES:
            player.subtractMoney(200);
            std::cout << player.getName() << " pays the Doctor $200 in fees!" << std::endl;
            break;
        case Action::STOCK_SALE:
            player.addMoney(100);
            std::cout << player.getName() << " was paid $100 after selling stock!" << std::endl;
            break;
        case Action::GET_OUT_OF_JAIL:
            if (player.getPosition() == 10)
            {
                std::cout << player.getName() << " got out of jail!" << std::endl;
                player.setPosition(0);
            }
            break;
    }
}

const std::string& CommunityChestCard::getDescription() const {
    return description;
}