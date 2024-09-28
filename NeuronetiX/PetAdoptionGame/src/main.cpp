/**
 * @file main.cpp
 * @author Abdullah Reda
 * @brief Contain the main function
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/Game.hpp"


/**
 * @brief Main function that creates the Game object and starts the game.
 * @return Returns 0 upon successful execution.
 */
int main() {
    Game game;      // Create an instance of the Game class
    game.start();   // Start the game
    return 0;       // Exit the program
}