/*********************************************************************************
 * Author:               Abdullah R.Hebashi
 * Creation Data:        23 Aug, 2024
 * Version:              v1.0
 * Compiler:			 GCC
*********************************************************************************/
/*********************************************************************************
 * Version      Date              Author                        Description
 * v1.0         23 Aug, 2024      Abdullah R.Hebashi            Initial Creation
*********************************************************************************/


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