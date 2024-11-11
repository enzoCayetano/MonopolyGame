#include "Deck.h"

void Deck::initializeDecks() 
{
    // Chance Card initialize list
    std::list<ChanceCard> chanceCards = 
    {
        ChanceCard(ChanceCard::Action::MOVE_TO_GO, "Advance to Go (Collect $200)"),
        ChanceCard(ChanceCard::Action::GO_TO_JAIL, "Go to Jail"),
        ChanceCard(ChanceCard::Action::PAY_TAX, "Pay poor tax of $15"),
        ChanceCard(ChanceCard::Action::COLLECT_MONEY, "Collect $100 from the bank"),
    };

    // Community chest card initialize list
    std::list<CommunityChestCard> communityChestCards = 
    {
        CommunityChestCard(CommunityChestCard::Action::DOCTOR_FEES, "Doctor's fees – Pay $200"),
        CommunityChestCard(CommunityChestCard::Action::STOCK_SALE, "From sale of stock you get $50"),
        CommunityChestCard(CommunityChestCard::Action::GET_OUT_OF_JAIL, "Get out of jail free card!"),
    };

    // Shuffle the cards (BROKEN)
    //    std::random_device rd;
    //    std::mt19937 g(rd());
    //    std::shuffle(chanceCards.begin(), chanceCards.end(), g);
    //    std::shuffle(communityChestCards.begin(), communityChestCards.end(), g);

    // Transfer shuffled cards to the stacks
    for (const auto& card : chanceCards) 
    {
        chanceDeck.push(card);
    }
    for (const auto& card : communityChestCards) 
    {
        communityChestDeck.push(card);
    }
}

void Deck::drawChanceCard(Player& player)
{
    if (chanceDeck.empty())
    {
        std::cout << "No more chance cards available!" << std::endl;
        return;
    }
    
    ChanceCard card = chanceDeck.top();
    chanceDeck.pop();
    
    std::cout << player.getName() << " drew a Chance card: " << card.getDescription() << std::endl;
    card.applyCard(player);
}

void Deck::drawCommunityChestCard(Player& player)
{
    if (communityChestDeck.empty())
    {
        std::cout << "No more chance cards available!" << std::endl;
        return;
    }
    
    CommunityChestCard card = communityChestDeck.top();
    communityChestDeck.pop();
    
    std::cout << player.getName() << " drew a Community Chest card: " << card.getDescription() << std::endl;
    card.applyCard(player);
}