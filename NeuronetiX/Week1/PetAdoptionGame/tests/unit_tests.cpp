#include <gtest/gtest.h>
#include "../include/Pet.hpp"
#include "../include/Game.hpp"


// Test that feeding decreases hunger
TEST(PetTest, HungerLevelDecrease) {
    std::string name = "Bill";
    Pet myPet(name);
    myPet.feed();
    EXPECT_EQ(myPet.getHungerLevel(), 90);  // Assuming initial hunger is 90 and decreases by 10
}

// Test that playing decreases happiness
TEST(PetTest, HappinessLevelDecrease) {
    std::string name = "Bill";
    Pet myPet(name);
    myPet.play();
    EXPECT_EQ(myPet.getHappinessLevel(), 90);  // Assuming initial happiness is 90 and decreases by 10
}

// Test critical condition when hunger reaches 0
TEST(PetTest, CriticalCondition_Hunger) {
    std::string name = "Bill";
    Pet myPet(name);
    Game myGame;
    for(int i = 0; i < 10; ++i) {
        myPet.feed();
    }
    EXPECT_EQ(myPet.getHungerLevel(), 0);
    EXPECT_TRUE(myGame.isCritical());
}

// Test critical condition when happiness reaches 0
TEST(PetTest, CriticalCondition_Happiness) {
    std::string name = "Bill";
    Pet myPet(name);
    Game myGame;
    for(int i = 0; i < 10; ++i) {
        myPet.play();
    }
    EXPECT_EQ(myPet.getHappinessLevel(), 0);
    EXPECT_TRUE(myGame.isCritical());
}


// Entry point for running all tests
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}