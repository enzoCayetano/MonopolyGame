#include "Board.h"

// Definition of GraphNode structure
struct GraphNode
{
    Property* property;      // The property represented by this node
    GraphNode* next;         // Pointer to the next property in the graph
    GraphNode* prev;         // Pointer to the previous property (optional, if bi-directional links are needed)
};

// Constructor to initialize head and tail pointers
Board::Board()
{
    head = nullptr;
    tail = nullptr;
}

// Helper function to create a new graph node
GraphNode* Board::createGraphNode(Property* property)
{
    GraphNode* newNode = new GraphNode;
    newNode->property = property;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

// initialize board
void Board::initializeBoard()
{
    // Initialize properties
    Property* go = new Property("Go", 0, 0);
    Property* medAve = new Property("Mediterranean Avenue", 60, 2);
    Property* baltAve = new Property("Baltic Avenue", 60, 4);
    Property* commChest1 = new Property("Community Chest", 0, 0);
    Property* incomeTax = new Property("Income Tax", 0, -200);
    Property* readingRR = new Property("Reading Railroad", 200, 25);
    Property* orientalAve = new Property("Oriental Avenue", 100, 6);
    Property* chance1 = new Property("Chance", 0, 0);
    Property* vermontAve = new Property("Vermont Avenue", 100, 6);
    Property* connecticutAve = new Property("Connecticut Avenue", 120, 8);
    Property* jail = new Property("Jail", 0, 0);
    Property* stCharlesPlace = new Property("St. Charles Place", 140, 10);
    Property* electricCo = new Property("Electric Company", 150, 0);
    Property* statesAve = new Property("States Avenue", 140, 10);
    Property* virginiaAve = new Property("Virginia Avenue", 160, 12);
    Property* pennRR = new Property("Pennsylvania Railroad", 200, 25);
    Property* stJamesPlace = new Property("St. James Place", 180, 14);
    Property* commChest2 = new Property("Community Chest", 0, 0);
    Property* tennesseeAve = new Property("Tennessee Avenue", 180, 14);
    Property* newYorkAve = new Property("New York Avenue", 200, 16);
    Property* freeParking = new Property("Free Parking", 0, 0);
    Property* kentuckyAve = new Property("Kentucky Avenue", 220, 18);
    Property* chance2 = new Property("Chance", 0, 0);
    Property* indianaAve = new Property("Indiana Avenue", 220, 18);
    Property* illinoisAve = new Property("Illinois Avenue", 240, 20);
    Property* boRR = new Property("B&O Railroad", 200, 25);
    Property* atlanticAve = new Property("Atlantic Avenue", 260, 22);
    Property* ventnorAve = new Property("Ventnor Avenue", 260, 22);
    Property* waterWorks = new Property("Water Works", 150, 0);
    Property* marvinGardens = new Property("Marvin Gardens", 280, 24);
    Property* goToJail = new Property("Go to Jail", 0, 0);
    Property* pacificAve = new Property("Pacific Avenue", 300, 26);
    Property* northCarolinaAve = new Property("North Carolina Avenue", 300, 26);
    Property* commChest3 = new Property("Community Chest", 0, 0);
    Property* pennsylvaniaAve = new Property("Pennsylvania Avenue", 320, 28);
    Property* shortLineRR = new Property("Short Line Railroad", 200, 25);
    Property* chance3 = new Property("Chance", 0, 0);
    Property* parkPlace = new Property("Park Place", 350, 35);
    Property* luxuryTax = new Property("Luxury Tax", 0, -100);
    Property* boardwalk = new Property("Boardwalk", 400, 50);

    // Create graph nodes and link them
    head = createGraphNode(go);
    GraphNode* current = head;

    // Add the rest of the properties to the linked list
    GraphNode* medAveNode = createGraphNode(medAve);
    current->next = medAveNode;
    medAveNode->prev = current;
    current = medAveNode;

    GraphNode* baltAveNode = createGraphNode(baltAve);
    current->next = baltAveNode;
    baltAveNode->prev = current;
    current = baltAveNode;

    GraphNode* commChest1Node = createGraphNode(commChest1);
    current->next = commChest1Node;
    commChest1Node->prev = current;
    current = commChest1Node;

    GraphNode* incomeTaxNode = createGraphNode(incomeTax);
    current->next = incomeTaxNode;
    incomeTaxNode->prev = current;
    current = incomeTaxNode;

    GraphNode* readingRRNode = createGraphNode(readingRR);
    current->next = readingRRNode;
    readingRRNode->prev = current;
    current = readingRRNode;

    GraphNode* orientalAveNode = createGraphNode(orientalAve);
    current->next = orientalAveNode;
    orientalAveNode->prev = current;
    current = orientalAveNode;

    GraphNode* chance1Node = createGraphNode(chance1);
    current->next = chance1Node;
    chance1Node->prev = current;
    current = chance1Node;

    GraphNode* vermontAveNode = createGraphNode(vermontAve);
    current->next = vermontAveNode;
    vermontAveNode->prev = current;
    current = vermontAveNode;

    GraphNode* connecticutAveNode = createGraphNode(connecticutAve);
    current->next = connecticutAveNode;
    connecticutAveNode->prev = current;
    current = connecticutAveNode;

    GraphNode* jailNode = createGraphNode(jail);
    current->next = jailNode;
    jailNode->prev = current;
    current = jailNode;

    GraphNode* stCharlesPlaceNode = createGraphNode(stCharlesPlace);
    current->next = stCharlesPlaceNode;
    stCharlesPlaceNode->prev = current;
    current = stCharlesPlaceNode;

    GraphNode* electricCoNode = createGraphNode(electricCo);
    current->next = electricCoNode;
    electricCoNode->prev = current;
    current = electricCoNode;

    GraphNode* statesAveNode = createGraphNode(statesAve);
    current->next = statesAveNode;
    statesAveNode->prev = current;
    current = statesAveNode;

    GraphNode* virginiaAveNode = createGraphNode(virginiaAve);
    current->next = virginiaAveNode;
    virginiaAveNode->prev = current;
    current = virginiaAveNode;

    GraphNode* pennRRNode = createGraphNode(pennRR);
    current->next = pennRRNode;
    pennRRNode->prev = current;
    current = pennRRNode;

    GraphNode* stJamesPlaceNode = createGraphNode(stJamesPlace);
    current->next = stJamesPlaceNode;
    stJamesPlaceNode->prev = current;
    current = stJamesPlaceNode;

    GraphNode* commChest2Node = createGraphNode(commChest2);
    current->next = commChest2Node;
    commChest2Node->prev = current;
    current = commChest2Node;

    GraphNode* tennesseeAveNode = createGraphNode(tennesseeAve);
    current->next = tennesseeAveNode;
    tennesseeAveNode->prev = current;
    current = tennesseeAveNode;

    GraphNode* newYorkAveNode = createGraphNode(newYorkAve);
    current->next = newYorkAveNode;
    newYorkAveNode->prev = current;
    current = newYorkAveNode;

    GraphNode* freeParkingNode = createGraphNode(freeParking);
    current->next = freeParkingNode;
    freeParkingNode->prev = current;
    current = freeParkingNode;

    GraphNode* kentuckyAveNode = createGraphNode(kentuckyAve);
    current->next = kentuckyAveNode;
    kentuckyAveNode->prev = current;
    current = kentuckyAveNode;

    GraphNode* chance2Node = createGraphNode(chance2);
    current->next = chance2Node;
    chance2Node->prev = current;
    current = chance2Node;

    GraphNode* indianaAveNode = createGraphNode(indianaAve);
    current->next = indianaAveNode;
    indianaAveNode->prev = current;
    current = indianaAveNode;

    GraphNode* illinoisAveNode = createGraphNode(illinoisAve);
    current->next = illinoisAveNode;
    illinoisAveNode->prev = current;
    current = illinoisAveNode;

    GraphNode* boRRNode = createGraphNode(boRR);
    current->next = boRRNode;
    boRRNode->prev = current;
    current = boRRNode;

    GraphNode* atlanticAveNode = createGraphNode(atlanticAve);
    current->next = atlanticAveNode;
    atlanticAveNode->prev = current;
    current = atlanticAveNode;

    GraphNode* ventnorAveNode = createGraphNode(ventnorAve);
    current->next = ventnorAveNode;
    ventnorAveNode->prev = current;
    current = ventnorAveNode;

    GraphNode* waterWorksNode = createGraphNode(waterWorks);
    current->next = waterWorksNode;
    waterWorksNode->prev = current;
    current = waterWorksNode;

    GraphNode* marvinGardensNode = createGraphNode(marvinGardens);
    current->next = marvinGardensNode;
    marvinGardensNode->prev = current;
    current = marvinGardensNode;

    GraphNode* goToJailNode = createGraphNode(goToJail);
    current->next = goToJailNode;
    goToJailNode->prev = current;
    current = goToJailNode;

    GraphNode* pacificAveNode = createGraphNode(pacificAve);
    current->next = pacificAveNode;
    pacificAveNode->prev = current;
    current = pacificAveNode;

    GraphNode* northCarolinaAveNode = createGraphNode(northCarolinaAve);
    current->next = northCarolinaAveNode;
    northCarolinaAveNode->prev = current;
    current = northCarolinaAveNode;

    GraphNode* commChest3Node = createGraphNode(commChest3);
    current->next = commChest3Node;
    commChest3Node->prev = current;
    current = commChest3Node;

    GraphNode* pennsylvaniaAveNode = createGraphNode(pennsylvaniaAve);
    current->next = pennsylvaniaAveNode;
    pennsylvaniaAveNode->prev = current;
    current = pennsylvaniaAveNode;

    GraphNode* shortLineRRNode = createGraphNode(shortLineRR);
    current->next = shortLineRRNode;
    shortLineRRNode->prev = current;
    current = shortLineRRNode;

    GraphNode* chance3Node = createGraphNode(chance3);
    current->next = chance3Node;
    chance3Node->prev = current;
    current = chance3Node;

    GraphNode* parkPlaceNode = createGraphNode(parkPlace);
    current->next = parkPlaceNode;
    parkPlaceNode->prev = current;
    current = parkPlaceNode;

    GraphNode* luxuryTaxNode = createGraphNode(luxuryTax);
    current->next = luxuryTaxNode;
    luxuryTaxNode->prev = current;
    current = luxuryTaxNode;

    GraphNode* boardwalkNode = createGraphNode(boardwalk);
    current->next = boardwalkNode;
    boardwalkNode->prev = current;
    current = boardwalkNode;

    // Tail points to the last property node
    tail = current;
}


void Board::displayBoardStatus() const
{
    GraphNode* current = head;
    while (current != nullptr)
    {
        Property* property = current->property;
        std::cout << "Position: " << property->getName()
                  << ", Owner: " << property->getOwner()
                  << ", Cost: $" << property->getCost()
                  << ", Rent: $" << property->getRent()
                  << ", Owned: " << (property->getIsOwned() ? "Yes" : "No")
                  << std::endl;
        current = current->next;
    }
}

// function to handle property based on player landing
void Board::handleProperty(Player& player, Property& property)
{
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

        auto ownerIt = std::find_if(players.begin(), players.end(),
                                    [&](Player& p) { return p.getName() == property.getOwner(); });
        if (ownerIt != players.end())
        {
            ownerIt->addMoney(rent);
            std::cout << player.getName() << " paid $" << rent << " rent to " << ownerIt->getName() << std::endl;
        }
    }
}

// move func
void Board::movePlayer(Player& player, int steps)
{
    GraphNode* current = head;
    int position = 0;  // start at first position

    // traverse the graph and move the player based on steps
    while (current != nullptr && position < steps)
    {
        current = current->next;  // Move to next node
        position++;
    }

    if (current != nullptr)
    {
        // player moves to the property at the current node
        handleProperty(player, *(current->property));
    }
}

GraphNode* Board::getHead() const
{
    return head;
}

GraphNode* Board::getTail() const
{
    return tail;
}

int Board::getSize() const
{
    int size = 0;
    GraphNode* current = head;
    while (current != nullptr)
    {
        size++;
        current = current->next;
    }
    return size;
}

Property& Board::getProperty(int position)
{
    GraphNode* current = head;
    int currentPosition = 0;
    
    while (current != nullptr)
    {
        if (currentPosition == position)
        {
            return *(current->property);  // Return the Property at the given position
        }
        current = current->next;
        currentPosition++;
    }

    // Handle error if position is out of bounds
    throw std::out_of_range("Invalid position on the board");
}
