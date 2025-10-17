# Specify the minimum version of CMake required to build this project
cmake_minimum_required(VERSION 3.30.2)

# Define the project name and version number
project(PetAdoptionGame VERSION 1.0)

# Specify the C++ standard to be used
set(CMAKE_CXX_STANDARD 23)                  # Use C++23
set(CMAKE_CXX_STANDARD_REQUIRED True)       # Ensure the C++ standard is required

# Add the include directories (header files)
include_directories(include)

# Set output directory for all executables to be inside build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the executable target with the main source file
add_executable(PetAdoptionGame src/main.cpp src/Game.cpp src/Pet.cpp)

# Link the target to the source files
target_sources(PetAdoptionGame PRIVATE src/Game.cpp src/Pet.cpp)


# Fetch GoogleTest package from vcpkg
find_package(GTest CONFIG REQUIRED)

# Set output directory for all executables to be inside build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Create the unit tests executable
add_executable(runUnitTests tests/unit_tests.cpp src/Game.cpp src/Pet.cpp)

# Link GoogleTest and GoogleMock
target_link_libraries(runUnitTests PRIVATE GTest::gtest GTest::gtest_main)

# Enable testing support
enable_testing()

# Add a test using CTest
add_test(NAME UnitTests COMMAND runUnitTests)


find_package(pthreads REQUIRED)

# Add GLFW, GLAD and OpenGL via vcpkg
find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(OpenGL REQUIRED)

# Include directories for core game logic
include_directories(src include)

# Add the core game logic source files
add_library(GameLogic src/Game.cpp src/Pet.cpp)

# Include directories from third-party
include_directories(third-party/imgui)
include_directories(third-party/imgui/backends)
include_directories(third-party/stb_image.h)

# Add ImGui source files
set(IMGUI_SOURCES
    third-party/imgui/imgui.cpp
    third-party/imgui/imgui_draw.cpp
    third-party/imgui/imgui_widgets.cpp
    third-party/imgui/imgui_tables.cpp
    third-party/imgui/backends/imgui_impl_glfw.cpp
    third-party/imgui/backends/imgui_impl_opengl3.cpp
)

# Set output directory for all executables to be inside build/bin/
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add the GUI executable
add_executable(runUI ui/main.cpp ${IMGUI_SOURCES})

# Link libraries for GUI: GLFW, OpenGL, and ImGui
target_link_libraries(runUI PRIVATE glad::glad glfw OpenGL::GL GameLogic)