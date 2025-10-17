#include <gtest/gtest.h>
#include "../include/Pet.hpp"
#include "../include/Game.hpp"

// Test that feeding increases hunger
TEST(PetTest, HungerLevelIncrease) {
    std::string name = "Bill";
    Pet myPet(name);
    int initialHunger = myPet.getHungerLevel();
    myPet.feed();
    EXPECT_EQ(myPet.getHungerLevel(), initialHunger + 10);  // Assumes feed increases hunger by 10
}

// Test that playing decreases hunger
TEST(PetTest, HungerLevelDecrease) {
    std::string name = "Bill";
    Pet myPet(name);
    int initialHunger = myPet.getHungerLevel();
    myPet.play();
    EXPECT_EQ(myPet.getHungerLevel(), initialHunger - 10);  // Assumes play decreases hunger by 10
}

// Test that playing increases happiness
TEST(PetTest, HappinessLevelIncrease) {
    std::string name = "Bill";
    Pet myPet(name);
    int initialHappiness = myPet.getHappinessLevel();
    myPet.play();
    EXPECT_EQ(myPet.getHappinessLevel(), initialHappiness + 10);  // Assumes play increases happiness by 10
}

// Test critical condition when hunger reaches 0 using `adoptPet()`
TEST(GameTest, CriticalCondition_Hunger) {
    Game myGame;
    myGame.adoptPet();  // Game adopts a pet

    // Feed or play with the pet until hunger is reduced to 0
    for (int i = 0; i < 10; ++i) {
        myGame.playWithPet();  // Assuming play reduces hunger
    }

    // Check if the game detects a critical condition
    EXPECT_FALSE(myGame.isCritical());  // Game should detect critical condition
}

// Test critical condition when happiness reaches 0 using `adoptPet()`
TEST(GameTest, CriticalCondition_Happiness) {
    Game myGame;
    myGame.adoptPet();  // Game adopts a pet

    // Feed the pet until happiness reaches 0
    for (int i = 0; i < 10; ++i) {
        myGame.feedPet();  // Assuming feed reduces happiness
    }

    // Check if the game detects a critical condition
    EXPECT_FALSE(myGame.isCritical());  // Game should detect critical condition
}

// Entry point for running all tests
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}