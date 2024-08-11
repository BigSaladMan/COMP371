#ifndef RENDERING_H
#define RENDERING_H

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <string>
#include <vector>

// Structure to represent a vertex
struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 texCoords;
};

// Structure to represent a mesh
struct Mesh {
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    GLuint VAO;
};

// Function to load an OBJ file and return a Mesh object
// Parameters:
//   filePath - Path to the OBJ file
// Returns:
//   A Mesh object containing vertex and index data
Mesh loadOBJ(const std::string& filePath);

// Function to create a VAO (Vertex Array Object) for the loaded mesh
// Parameters:
//   mesh - The Mesh object to create a VAO for
// Returns:
//   The VAO identifier (GLuint)
GLuint createMeshVAO(const Mesh& mesh);

// Function to render the loaded mesh
// Parameters:
//   mesh - The Mesh object to render
//   shaderProgram - The OpenGL shader program to use for rendering
void renderMesh(const Mesh& mesh, GLuint shaderProgram);

#endif // RENDERING_H
