#include "MonopolyGame.h"

MonopolyGame::MonopolyGame()
{
    // Initialize the deck
    deck.initializeDecks();

    // Initialize the board
    board.initializeBoard();
}

void MonopolyGame::setupPlayers()
{
    int numPlayers;
    std::cout << "Enter number of players (or 0 to quit): ";
    std::cin >> numPlayers;

    if (numPlayers == 0) { std::cout << "Quitting..."; }

    for (int i = 0; i < numPlayers; i++)
    {
        std::string name;
        std::cout << "Enter name for player " << i + 1 << ": ";
        std::cin >> name;
        playerManager.addPlayer(name);
    }

    if (numPlayers > 1)
    {
       std::cout << "Players setup complete!" << std::endl; 
    }
    else
    {
        // Implement AI
        // std::cout << "Since you are solo, would you like to implement A.I. players?" << std::endl;
    }
}

// ----- GAME LOOP -----
void MonopolyGame::playGame(int numTurns) 
{
    setupPlayers();
    gameOver = false;
    
    int turn = 0;
    while (turn < numTurns && !gameOver)
    {
        Player* currentPlayer = playerManager.getNextPlayer();
        std::cout << "Turn " << turn + 1 << ": " << currentPlayer->getName() << "'s turn." << std::endl;
        
        takeTurn(*currentPlayer);
        
        if (currentPlayer->getMoney() <= 0)
        {
            std::cout << currentPlayer->getName() << " is bankrupt!" << std::endl;
            gameOver = true;
        }
        
        turn++;
    }
    
    std::cout << "Game over!" << std::endl;
}

// Take turn
void MonopolyGame::takeTurn(Player& player) 
{
    int diceRoll = rollDice();
    player.setPosition((player.getPosition() + diceRoll) % board.getSize());
    auto& property = board.getProperty(player.getPosition());
    std::cout << "Money: $" << player.getMoney() << std::endl;

    std::cout << player.getName() << " rolled a [" << diceRoll 
              << "] and landed on " << property.getName() << "." << std::endl;

    if (property.getName() == "Free Parking") {
        std::cout << "You landed on Free Parking. Nothing happens!" << std::endl;
    } else {
        board.handleProperty(player, property);
    }
    
    presentPlayerOptions(player);
}

// roll the dice
int MonopolyGame::rollDice() 
{
    return (std::rand() % 6 + 1) + (std::rand() % 6 + 1);
}

// Present options to the player
void MonopolyGame::presentPlayerOptions(Player& player) 
{
    std::cout << std::endl; // space
    char action;
    std::cout << player.getName() << "'s turn!" << std::endl;
    std::cout << "Current space: " << player.getPosition() << std::endl;
    std::cout << "Current money: $" << player.getMoney() << std::endl;
    std::cout << "What would you like to do next?" << std::endl;
    std::cout << "1. End Turn" << std::endl;
    std::cout << "2. Use Chance Card" << std::endl;
    std::cout << "3. Use Community Chest Card" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> action;

    switch (action) 
    {
        case '1':
            std::cout << player.getName() << " ended their turn." << std::endl;
            break;
        case '2':
            deck.drawChanceCard(player);
            break;
        case '3':
            deck.drawCommunityChestCard(player);
            break;
        default:
            std::cout << "Invalid choice. Ending turn." << std::endl;
    }

    std::cout << std::endl;
}