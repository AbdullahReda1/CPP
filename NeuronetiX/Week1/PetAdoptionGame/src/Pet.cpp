/**
 * @file Pet.cpp
 * @author Abdullah Reda
 * @brief Contain the pet implementation
 * @version 0.1
 * @date 2024-08-23
 * 
 * @copyright Copyright (c) 2024
 * 
 */
#include "../include/Pet.hpp"
#include <iostream>


/**
 * @brief Constructs a new Pet object with the given name and default levels.
 * @param petName The name of the pet.
 */
Pet::Pet(const std::string &petName): name(petName), hungerLevel(50), happinessLevel(50) {}

/**
 * @fn string getName() const
 * @brief Gets the name of the pet.
 * @details Constant member method.
 * @return The name of the pet.
 */
std::string Pet::getName() const { return name; }

/**
 * @fn int getHungerLevel() const
 * @brief Gets the hunger level of the pet.
 * @details Constant member method.
 * @return The hunger level of the pet.
 */
int Pet::getHungerLevel() const { return hungerLevel; }

/**
 * @fn int getHappinessLevel() const
 * @brief Gets the happiness level of the pet.
 * @details Constant member method.
 * @return The happiness level of the pet.
 */
int Pet::getHappinessLevel() const { return happinessLevel; }

/**
 * @fn void feed()
 * @brief Feeds the pet to increase its hunger level.
 */
void Pet::feed() {
    
}

/**
 * @fn void play()
 * @brief Plays with the pet to increase its happiness level.
 */
void Pet::play() {

}

/**
 * @fn void checkStatus() const
 * @brief Displays the current status of the pet.
 * @details Constant member method.
 */
void Pet::checkStatus() const {

}