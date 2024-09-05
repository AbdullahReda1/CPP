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
# Include vcpkg for package management
if(CMAKE_TOOLCHAIN_FILE)
    message(STATUS "Using vcpkg toolchain from: ${CMAKE_TOOLCHAIN_FILE}")
endif()

# Fetch GoogleTest package from vcpkg
find_package(GTest CONFIG REQUIRED)

add_executable(runUnitTests tests/unit_tests.cpp src/Game.cpp src/Pet.cpp)

# Link GoogleTest and GoogleMock
target_link_libraries(runUnitTests PRIVATE GTest::gtest GTest::gtest_main)

# Enable testing support
enable_testing()

# Add a test using CTest
add_test(NAME UnitTests COMMAND runUnitTests)