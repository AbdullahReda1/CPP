#include <glad/glad.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>

#include <iostream>
#include "../include/Pet.hpp"
#include "../include/Game.hpp"

// Define window size as macros
#define WINDOW_WIDTH    700
#define WINDOW_HEIGHT   400

// Function to render the game UI
void renderUI(Game& game, Pet& pet, bool& gameOver) {
    ImGui::Begin("Pet Adoption Game");

    if (!gameOver) {
        // Display pet's current stats
        ImGui::Text("Pet Name: %s", pet.getName().c_str());
        ImGui::Text("Hunger Level: %d", pet.getHungerLevel());
        ImGui::Text("Happiness Level: %d", pet.getHappinessLevel());

        // Buttons to interact with the pet
        if (ImGui::Button("Feed Pet")) {
            pet.feed();  // Feed the pet
        }

        if (ImGui::Button("Play with Pet")) {
            pet.play();  // Play with the pet
        }

        // Check if the game is over (critical level reached)
        if ((pet.getHappinessLevel() <= 0) || (pet.getHungerLevel() <= 0)) {
            gameOver = true;
        }
    } else {
        // Show "Game Over" message and block further interaction
        ImGui::Text("Game Over! Your pet is no longer adoptable.");
        ImGui::Text("Hunger Level: %d", pet.getHungerLevel());
        ImGui::Text("Happiness Level: %d", pet.getHappinessLevel());
    }

    // Button to close the window (always available)
    if (ImGui::Button("Close Window")) {
        glfwSetWindowShouldClose(glfwGetCurrentContext(), GLFW_TRUE);
    }

    ImGui::End();
}

int main() {
    // Setup GLFW and OpenGL
    glfwSetErrorCallback([](int error, const char* description) {
        std::cerr << "GLFW Error: " << description << std::endl;
    });

    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    const char* glsl_version = "#version 130";
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

    // Create the window with size defined by macros
    GLFWwindow* window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Pet Adoption Game", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);  // Enable vsync

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    // Initialize Dear ImGui
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsClassic();  // Apply default style
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    bool petNameEntered = false;
    char petName[128] = "Enter Pet Name";
    Pet pet(petName);  // Initialize with default name

    bool gameOver = false;  // Track if the game is over
    Game game;

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll for events
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Ask for pet name if not entered
        if (!petNameEntered) {
            ImGui::Begin("Enter Pet Name");
            ImGui::InputText("Pet Name", petName, IM_ARRAYSIZE(petName));
            if (ImGui::Button("Start Game")) {
                pet = Pet(petName);  // Set the entered name
                petNameEntered = true;
            }
            ImGui::End();
        } else {
            // Render the game UI after pet name is entered
            renderUI(game, pet, gameOver);
        }

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);  // Handle window resize
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap buffers
        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}