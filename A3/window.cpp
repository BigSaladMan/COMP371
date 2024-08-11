// window.cpp
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.h"

GLFWwindow* initializeWindow(int width, int height, const char* title) {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return nullptr;
    }

    // Create a GLFW window
    GLFWwindow* window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    // Make the OpenGL context current
    glfwMakeContextCurrent(window);

    return window;
}
