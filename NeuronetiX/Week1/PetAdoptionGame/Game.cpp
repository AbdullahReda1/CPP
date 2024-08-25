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