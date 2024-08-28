/**
 * @file Game.cpp
 * @author Abdullah Reda
 * @brief Contain the the game implementation
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/Game.hpp"
#include <iostream>


/**
 * @brief Constructs a new Game object with no pet and sets the game as running.
 */
Game::Game() : pet(nullptr), isRunning(true) {}


/**
 * @brief Destroys the Game object and releases the memory allocated for the pet.
 */
Game::~Game() { delete pet; }


/**
 * @fn void start()
 * @brief Starts the main game loop, which continues until the user decides to end the game.
 */
void Game::start() {
    /* The Game is running now */
    while (isRunning) {
        showMenu();
        unsigned int choice;
        std::cin >> choice;
        handleChoice(choice);

        /* Jump to the `while` to restart the game if no pet is created */
        if (pet == nullptr) { continue; }

        /* Finish the `while` loop if the critical state comes */
        if (!isCritical()) {
            std::cout << "Game Over. " << pet->getName() << "'s condition has reached a critical level.\n" ;
            pet->checkStatus();
            isRunning = false;
        }
    }
}

/**
* @fn bool isCritical() const
* @brief Method to check if the pet's condition is critical
* @details Constant member method.
* @return true 
* @return false 
*/
bool Game::isCritical() const { return ((pet->getSatiationStatus()) & (pet->getHappinessStatus())); }

/**
 * @fn void showMenu() const
 * @brief Displays the main menu to the user.
 * @details Constant member method.
 */
void Game::showMenu() const {
    std::cout << "1. Adopt Pet\n"
              << "2. Feed Pet\n"
              << "3. Play with Pet\n"
              << "4. Check Status\n"
              << "5. End Game\n"
              << "Choose an option: ";
}

/**
 * @fn void handleChoice(int choice)
 * @brief Executes the user's choice from the menu.
 * @param choice The option selected by the user.
 */
void Game::handleChoice(int choice) {
    switch (choice) {
        case 1:
            adoptPet();
                break;
        case 2:
            feedPet();
                break;
        case 3:
            playWithPet();
                break;
        case 4:
            checkStatus();
                break;
        case 5:
            endGame();
                break;
        default:
            std::cout << "Invalid choice. Please try again.\n";
                break;
    }
}

/**
 * @fn void adoptPet()
 * @brief Allows the user to adopt a new pet by entering a name.
 */
void Game::adoptPet() {
    if (pet == nullptr) {
        std::string name;
        std::cout << "Enter the name of your pet: ";
        std::cin >> name;
        pet = new Pet(name);
        std::cout << name << " has been adopted.\n";
    }
    else { std::cout << "You already have a pet!\n"; }
}

/**
 * @fn void feedPet()
 * @brief Increases the hunger level of the adopted pet.
 */
void Game::feedPet() {
    if (pet != nullptr) { pet->feed(); }
    else                { std::cout << "You need to adopt a pet first.\n"; }
}

/**
 * @fn void playWithPet()
 * @brief Increases the happiness level of the adopted pet.
 */
void Game::playWithPet() {
    if (pet != nullptr) { pet->play(); }
    else                { std::cout << "You need to adopt a pet first.\n"; }
}

/**
 * @fn void checkStatus() const
 * @brief Displays the current status of the adopted pet.
 * @details Constant member method.
 */
void Game::checkStatus() const {
    if (pet != nullptr) { pet->checkStatus(); }
    else                { std::cout << "You need to adopt a pet first.\n"; }
}

/**
 * @fn void endGame()
 * @brief Ends the game and displays the final status of the pet.
 */
void Game::endGame() {
    if (pet != nullptr) {
        std::cout << "Game Over. Your pet's final status:\n";
        pet->checkStatus();
    }
    isRunning = false;
}