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
    
}

/**
 * @fn void showMenu() const
 * @brief Displays the main menu to the user.
 * @details Constant member method.
 */
void Game::showMenu() const {
    
}

/**
 * @fn void handleChoice(int choice)
 * @brief Handles the user's choice from the menu.
 * @param choice The option selected by the user.
 */
void Game::handleChoice(int choice) {
    
}

/**
 * @fn void adoptPet()
 * @brief Allows the user to adopt a pet by entering a name.
 */
void Game::adoptPet() {
    
}

/**
 * @fn void feedPet()
 * @brief Increases the hunger level of the adopted pet.
 */
void Game::feedPet() {
    
}

/**
 * @fn void playWithPet()
 * @brief Increases the happiness level of the adopted pet.
 */
void Game::playWithPet() {
    
}

/**
 * @fn void checkStatus() const
 * @brief Displays the current status of the adopted pet.
 * @details Constant member method.
 */
void Game::checkStatus() const {
    
}

/**
 * @fn void endGame()
 * @brief Ends the game and displays the final status of the pet.
 */
void Game::endGame() {
    
}