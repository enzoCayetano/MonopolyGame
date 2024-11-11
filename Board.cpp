#include "Board.h"
#include "Player.h"
#include "Property.h"
#include "PlayerManager.h"

// Getters & Setters
const std::map<int, Property>& Board::getBoard() const { return board; }
void Board::setBoard(const std::map<int, Property>& newBoard) { board = newBoard; }
void Board::addProperty(int position, const Property& property) { board[position] = property; }
Property& Board::getProperty(int position) { return board.at(position); }
int Board::getSize() const { return board.size(); }

void Board::displayBoardStatus() const
{
    for (const auto& pair : board)
    {
        const Property& property = pair.second;
        std::cout << "Position: " << pair.first 
                  << ", Name: " << property.getName()
                  << ", Owner: " << property.getOwner()
                  << ", Cost: $" << property.getCost()
                  << ", Rent: $" << property.getRent()
                  << ", Owned: " << (property.getIsOwned() ? "Yes" : "No") 
                  << std::endl;
    }
}

// Initialize property spaces on the board
// 40 spaces in total
void Board::initializeBoard() 
{
    board[0] = Property("Go", 0, 0); // Landing here gives $200 on passing
    board[1] = Property("Mediterranean Avenue", 60, 2);
    board[2] = Property("Community Chest", 0, 0);
    board[3] = Property("Baltic Avenue", 60, 4);
    board[4] = Property("Income Tax", 0, -200); // Tax deduction
    board[5] = Property("Reading Railroad", 200, 25);
    board[6] = Property("Oriental Avenue", 100, 6);
    board[7] = Property("Chance", 0, 0);
    board[8] = Property("Vermont Avenue", 100, 6);
    board[9] = Property("Connecticut Avenue", 120, 8);

    board[10] = Property("Jail", 0, 0); // Player just visiting or placed here when sent to jail
    board[11] = Property("St. Charles Place", 140, 10);
    board[12] = Property("Electric Company", 150, 0); // Special rent calculation
    board[13] = Property("States Avenue", 140, 10);
    board[14] = Property("Virginia Avenue", 160, 12);
    board[15] = Property("Pennsylvania Railroad", 200, 25);
    board[16] = Property("St. James Place", 180, 14);
    board[17] = Property("Community Chest", 0, 0);
    board[18] = Property("Tennessee Avenue", 180, 14);
    board[19] = Property("New York Avenue", 200, 16);

    board[20] = Property("Free Parking", 0, 0); // Safe space, no effect
    board[21] = Property("Kentucky Avenue", 220, 18);
    board[22] = Property("Chance", 0, 0);
    board[23] = Property("Indiana Avenue", 220, 18);
    board[24] = Property("Illinois Avenue", 240, 20);
    board[25] = Property("B&O Railroad", 200, 25);
    board[26] = Property("Atlantic Avenue", 260, 22);
    board[27] = Property("Ventnor Avenue", 260, 22);
    board[28] = Property("Water Works", 150, 0); // Special rent calculation
    board[29] = Property("Marvin Gardens", 280, 24);

    board[30] = Property("Go to Jail", 0, 0); // Player sent to Jail
    board[31] = Property("Pacific Avenue", 300, 26);
    board[32] = Property("North Carolina Avenue", 300, 26);
    board[33] = Property("Community Chest", 0, 0);
    board[34] = Property("Pennsylvania Avenue", 320, 28);
    board[35] = Property("Short Line Railroad", 200, 25);
    board[36] = Property("Chance", 0, 0);
    board[37] = Property("Park Place", 350, 35);
    board[38] = Property("Luxury Tax", 0, -100); // Tax deduction
    board[39] = Property("Boardwalk", 400, 50);
}

// Handle property within Board class
void Board::handleProperty(Player& player, Property& property)
{
    // Income tax space
    if (property.getName() == "Income Tax") 
    {
        int totalAssets = player.getMoney();

        for (const auto& propertyName : player.getProperties()) 
        {
            auto it = std::find_if(board.begin(), board.end(),
                [&](const std::pair<int, Property>& p) { return p.second.getName() == propertyName; });
            if (it != board.end()) 
            {
                totalAssets += it->second.getCost(); // Add the property's cost
            }
        }

        int tax = std::min(200, static_cast<int>(totalAssets * 0.10));
        // Deduct tax (either $200 or 10% of assets)
        player.subtractMoney(tax);

        std::cout << player.getName() << " has landed on Income Tax and paid $" << tax << std::endl;
        return;
    }

    if (!property.getIsOwned())
    {
        if (player.getMoney() >= property.getCost())
        {
            char choice;
            std::cout << "Do you want to buy this property for $" << property.getCost() << "? (y/n): ";
            std::cin >> choice;

            if (choice == 'y' || choice == 'Y')
            {
                player.subtractMoney(property.getCost());
                player.addProperty(property.getName());
                property.setOwner(player.getName());
                property.setIsOwned(true);
                std::cout << player.getName() << " bought " << property.getName() << " for $"
                          << property.getCost() << "!" << std::endl;
            }
            else
            {
                std::cout << player.getName() << " chose not to buy " << property.getName() << "." << std::endl;
            }
        }
    }
    else if (property.getOwner() != player.getName())
    {
        PlayerManager playerManager;
        std::list<Player> players = playerManager.getPlayers();
        int rent = property.getRent();
        player.subtractMoney(rent);

        // Distribute rent if current player does not own currently owned property
        auto ownerIt = std::find_if(players.begin(), players.end(),
                                    [&](Player& p) { return p.getName() == property.getOwner(); });
        if (ownerIt != players.end()) 
        {
            ownerIt->addMoney(rent);
            std::cout << player.getName() << " paid $" << rent << " rent to " << ownerIt->getName() << std::endl;
        }
    }
}