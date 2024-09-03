# Specify the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.30.2)

# Define the project name and version number
project(PetAdoptionGame VERSION 1.0)

# Specify the C++ standard to be used
set(CMAKE_CXX_STANDARD 23)                  # Use C++23
set(CMAKE_CXX_STANDARD_REQUIRED True)       # Ensure the C++ standard is required

set(CMAKE_VERBOSE_MAKEFILE ON)
set(CMAKE_BUILD_TYPE Debug)

# Add the include directories (header files)
include_directories(include)

# Add the executable target with the main source file
add_executable(PetAdoptionGame src/main.cpp src/Game.cpp src/Pet.cpp)

# Link the target to the source files
target_sources(PetAdoptionGame PRIVATE src/Game.cpp src/Pet.cpp)

# Unit Testing Section

# Google Test setup
# Manually specify the path to the Google Test include directory and libraries
set(GTEST_INCLUDE_DIRS "E:/ITI ES/GTest/Tool/googletest/googletest/include")
set(GTEST_LIBS_DIR "E:/ITI ES/GTest/Tool/googletest/build/lib/Debug")

# Include directories and link libraries
include_directories(${GTEST_INCLUDE_DIRS})
link_directories(${GTEST_LIBS_DIR})

# Enable testing for this project
enable_testing()

# Add the executable for running unit tests
add_executable(runUnitTests tests/unit_tests.cpp src/Game.cpp src/Pet.cpp)

# Link the Google Test libraries
target_link_libraries(runUnitTests PRIVATE ${GTEST_LIBS_DIR}/gtest.lib ${GTEST_LIBS_DIR}/gtest_main.lib)