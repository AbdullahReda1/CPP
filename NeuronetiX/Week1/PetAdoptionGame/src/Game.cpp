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
#include "Game.hpp"
#include <iostream>


/**
 * @brief Constructs a new Game object with no pet and sets the game as running.
 */
Game::Game() : pet(nullptr), isRunning(true) {}


/**
 * @brief Destroys the Game object and releases the memory allocated for the pet.
 */
Game::~Game() { delete pet; }