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