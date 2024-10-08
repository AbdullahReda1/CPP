/**
 * @file Pet.hpp
 * @author Abdullah Reda
 * @brief Contain the pet class
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#ifndef PET_HPP
#define PET_HPP


#include <string>


/**
 * @class Pet
 * @brief Represents a virtual pet that can be adopted, fed, and played with.
 */
class Pet {
    
    private:
        std::string name;                    ///< Name of the pet
        unsigned int hungerLevel;            ///< Hunger level of the pet (0-90)
        unsigned int happinessLevel;         ///< Happiness level of the pet (0-90)
        bool satiation;                      ///< Flag of zero satiation
        bool happiness;                      ///< Flag of zero happiness

    public:
        /**
        * @brief Constructs a new Pet object with the given name.
        * @param petName Name of the pet
        */
        Pet(const std::string &petName);

        /**
         * @fn string getName() const
         * @brief Gets the name of the pet.
         * @details Constant member method (getter function).
         * @return The name of the pet.
         */
        std::string getName() const;

        /**
         * @fn int getHungerLevel() const
         * @brief Gets the hunger level of the pet.
         * @details Constant member method (getter function).
         * @return The hunger level of the pet.
         */
        int getHungerLevel() const;

        /**
         * @fn int getHappinessLevel() const
         * @brief Gets the happiness level of the pet.
         * @details Constant member method (getter function).
         * @return The happiness level of the pet.
         */
        int getHappinessLevel() const;

        /**
         * @fn bool getSatiationStatus() const
         * @brief Get the Satiation Status object.
         * @details Constant member method (getter function).
         * @return true 
         * @return false 
         */
        bool getSatiationStatus() const;

        /**
         * @fn bool getHappinessStatus() const
         * @brief Get the Happiness Status object
         * @details Constant member method (getter function).
         * @return true 
         * @return false 
         */
        bool getHappinessStatus() const;

        /**
         * @fn void feed()
         * @brief Feeds the pet to increase its hunger level.
         */
        void feed();

        /**
         * @fn void play()
         * @brief Plays with the pet to increase its happiness level.
         */
        void play();

        /**
         * @fn void checkStatus() const
         * @brief Displays the current status of the pet.
         * @details Constant member method.
         */
        void checkStatus() const;
};


#endif // PET_HPP