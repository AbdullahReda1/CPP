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
 * @brief Feeds the pet, increasing its hunger level by 10, up to a maximum of 90.
 */
void Pet::feed() {
    if (hungerLevel < 90) {
        hungerLevel += 10;
        std::cout << name << " has been fed.\n";
    }
    else { std::cout << name << " is already full.\n"; } 
}

/**
 * @fn void play()
 * @brief Plays with the pet, increasing its happiness level by 10, up to a maximum of 90.
 */
void Pet::play() {
    if (happinessLevel < 90) {
        happinessLevel += 10;
        std::cout << name << " is happier now.\n";
    }
    else { std::cout << name << " is already too happy.\n"; } 
}

/**
 * @fn void checkStatus() const
 * @brief Displays the pet's current hunger and happiness levels.
 * @details Constant member method.
 */
void Pet::checkStatus() const {
    std::cout << name << "'s Hunger Level: "    << hungerLevel    << "\n";
    std::cout << name << "'s Happiness Level: " << happinessLevel << "\n";
}