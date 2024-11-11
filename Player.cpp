#include "Player.h"

Player::Player(const std::string& playerName, int startingMoney, int startPosition) : name(playerName), money(startingMoney), position(startPosition) {}

// Getters
std::string Player::getName() const { return name; }
int Player::getMoney() const { return money; }
int Player::getPosition() const { return position; }

// Setters
void Player::subtractMoney(int amount) { money -= amount; }
void Player::addMoney(int amount) { money += amount; }
void Player::setPosition(int newPos) { position = newPos; }

// Property settings
std::set<std::string> Player::getProperties() const { return properties; }
void Player::addProperty(const std::string& propertyName) { properties.insert(propertyName); }
void Player::removeProperty(const std::string& propertyName) { properties.erase(propertyName); }