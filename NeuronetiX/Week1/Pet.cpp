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


#include "Pet.hpp"
#include <iostream>


/**
 * @brief Constructs a new Pet object with the given name and default levels.
 * @param petName The name of the pet.
 */
Pet::Pet(const std::string &petName): name(petName), hungerLevel(50), happinessLevel(50) {}