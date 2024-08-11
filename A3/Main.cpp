#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include "window.h"
#include "rendering.h"
#include "transformations.h"
#include <iostream>
#include "tiny_obj_loader.h"
#include <vector>

// Initialize variables for transformations
glm::vec3 translation(0.0f, 0.0f, 0.0f);
float rotation = 0.0f;
float scale = 1.0f;

std::vector<float> vertices;
std::vector<unsigned int> indices;

void processInput(GLFWwindow* window) {
    const float translationDistance = 0.01f; // Distance for translation, 0.01f units
    const float rotationAngle = glm::radians(0.52f); // Rotation angle (0.52 degrees in radians)
    const float scaleFactor = 0.01f; // Scaling factor, 0.01f units

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
        rotation += rotationAngle; // Rotate counterclockwise
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        rotation -= rotationAngle; // Rotate clockwise
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        scale += scaleFactor; // Scale up
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        scale -= scaleFactor; // Scale down
}

void loadModel(const std::string& path) {
    tinyobj::attrib_t attrib;
    std::vector<tinyobj::shape_t> shapes;
    std::vector<tinyobj::material_t> materials;
    std::string warn, err;

    bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, path.c_str());

    if (!warn.empty()) {
        std::cout << warn << std::endl;
    }

    if (!err.empty()) {
        std::cerr << err << std::endl;
    }

    if (!ret) {
        exit(1);
    }

    // Loop over shapes
    for (size_t s = 0; s < shapes.size(); s++) {
        // Loop over faces (polygon)
        size_t index_offset = 0;
        for (size_t f = 0; f < shapes[s].mesh.num_face_vertices.size(); f++) {
            int fv = shapes[s].mesh.num_face_vertices[f];

            // Loop over vertices in the face.
            for (size_t v = 0; v < fv; v++) {
                // Access to vertex
                tinyobj::index_t idx = shapes[s].mesh.indices[index_offset + v];
                tinyobj::real_t vx = attrib.vertices[3 * idx.vertex_index + 0];
                tinyobj::real_t vy = attrib.vertices[3 * idx.vertex_index + 1];
                tinyobj::real_t vz = attrib.vertices[3 * idx.vertex_index + 2];
                vertices.push_back(vx);
                vertices.push_back(vy);
                vertices.push_back(vz);
                indices.push_back(indices.size());
            }
            index_offset += fv;
        }
    }
}

int main()
{
    // Initialize GLFW and create a window
    GLFWwindow* window = initializeWindow(800, 600, "Assignment");

    // Initialize GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return -1;
    }

    // Load the OBJ model
    loadModel("Bottle.mtl.obj");

    // Set up shaders
    GLuint shaderProgram = createShaderProgram();

    // Set up VAO and VBO for the OBJ model
    GLuint VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // Position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        processInput(window);

        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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

        // Render the OBJ model
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, vertices.size() / 3);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);
    glfwTerminate();

    return 0;
}
