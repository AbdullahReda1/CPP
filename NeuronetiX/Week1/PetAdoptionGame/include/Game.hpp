/**
 * @file Game.hpp
 * @author Abdullah Reda
 * @brief Contain the game class
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef GAME_HPP
#define GAME_HPP


#include "Pet.hpp"


/**
 * @class Game
 * @brief Manages the overall game logic, including pet adoption, user interaction, and game state.
 */
class Game {

    private:
        Pet* pet;                   ///< Pointer to the adopted pet
        bool isRunning;             ///< Flag to keep the game running

    public:
        /**
         * @brief Constructs a new Game object and initializes the game state.
         */
        Game();

        /**
         * @brief Destroys the Game object and ensures proper cleanup of dynamic memory.
         */
        ~Game();
};


#endif // GAME_HPP