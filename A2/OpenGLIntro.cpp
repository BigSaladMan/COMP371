#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "window.h"
#include "rendering.h"
#include "transformations.h"
#include <iostream>


using namespace std;

// Initialize variables for transformations
glm::vec3 translation(0.0f, 0.0f, 0.0f);
float rotation = 0.0f;
float scale = 1.0f;

void processInput(GLFWwindow* window) {
    const float translationDistance = 0.1f; // Distance for translation
    const float rotationAngle = glm::radians(30.0f); // Rotation angle (30 degrees in radians)
    const float scaleFactor = 0.05f; // Reduced scaling factor


    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true); // Close the window when ESC is pressed

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        translation.y += translationDistance; // Translate up
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        translation.y -= translationDistance; // Translate down
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        translation.x -= translationDistance; // Translate left
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        translation.x += translationDistance; // Translate right
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        rotation += rotationAngle; // Rotate anticlockwise
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        rotation -= rotationAngle; // Rotate clockwise
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        scale += scaleFactor; // Scale up
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        scale -= scaleFactor; // Scale down
}

int main() {
    // Initialize GLFW and create a window
    GLFWwindow* window = initializeWindow(800, 600, "Assignment");

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Set up shaders, VAO, and VBO
    GLuint shaderProgram = createShaderProgram();
    GLuint VAO = createTriangleVAO();

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT);

        // Use the shader program
        glUseProgram(shaderProgram);

        // Create transformation matrices
        glm::mat4 model = glm::mat4(1.0f);
        model = glm::translate(model, translation);
        model = glm::rotate(model, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
        model = glm::scale(model, glm::vec3(scale, scale, scale));

        // Set the uniform for the transformation matrix
        GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

        // Render the triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();

    return 0;
}
