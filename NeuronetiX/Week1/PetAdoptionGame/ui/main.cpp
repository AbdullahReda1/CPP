#include <glad/glad.h>
#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"
#include <GLFW/glfw3.h>
#include <iostream>
#include "../include/Pet.hpp"
#include "../include/Game.hpp"

// Definition of window size as macros
#define WINDOW_WIDTH    1280
#define WINDOW_HEIGHT   720

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
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init(glsl_version);

    // Create game and pet objects
    Game game;
    Pet pet("Beta");

    bool gameOver = false;  // Track if the game is over

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Poll for events
        glfwPollEvents();

        // Start ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Render the game UI
        renderUI(game, pet, gameOver);

        // Rendering
        ImGui::Render();
        int display_w = WINDOW_WIDTH, display_h = WINDOW_HEIGHT;
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