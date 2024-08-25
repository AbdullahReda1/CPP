#ifndef PET_HPP
#define PET_HPP


#include <string>


/**
 * @class Pet
 * @brief Represents a virtual pet that can be adopted, fed, and played with.
 */
class Pet {
    
    private:
        std::string name;           ///< Name of the pet
        int hungerLevel;            ///< Hunger level of the pet (0-90)
        int happinessLevel;         ///< Happiness level of the pet (0-90)

    public:
        /**
        * @brief Constructs a new Pet object with the given name.
        * @param petName Name of the pet
        */
        Pet(const std::string &petName);
};


#endif // PET_HPP