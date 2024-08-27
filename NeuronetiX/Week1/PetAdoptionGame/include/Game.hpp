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

        /**
         * @fn void start()
         * @brief Starts the main game loop, which continues until the user decides to end the game.
         */
        void start();

        /**
         * @fn void showMenu() const
         * @brief Displays the main menu to the user.
         * @details Constant member method.
         */
        void showMenu() const;

        /**
         * @fn void handleChoice(int choice)
         * @brief Handles the user's choice from the menu.
         * @param choice The option selected by the user.
         */
        void handleChoice(int choice);

        /**
         * @fn void adoptPet()
         * @brief Allows the user to adopt a pet by entering a name.
         */
        void adoptPet();

        /**
         * @fn void feedPet()
         * @brief Increases the hunger level of the adopted pet.
         */
        void feedPet();

        /**
         * @fn void playWithPet()
         * @brief Increases the happiness level of the adopted pet.
         */
        void playWithPet();

        /**
         * @fn void checkStatus() const
         * @brief Displays the current status of the adopted pet.
         * @details Constant member method.
         */
        void checkStatus() const;

        /**
         * @fn void endGame()
         * @brief Ends the game and displays the final status of the pet.
         */
        void endGame();        
};


#endif // GAME_HPP