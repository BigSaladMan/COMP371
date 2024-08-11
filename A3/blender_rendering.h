#ifndef BLENDER_RENDERING_H
#define BLENDER_RENDERING_H

#include <GL/glew.h>
#include <string>
#include <vector>
#include <glm/glm.hpp> 

// Structure to represent a vertex
struct Vertex {
    glm::vec3 position;  // Position of the vertex
    glm::vec3 normal;    // Normal vector at the vertex
    glm::vec2 texCoords; // Texture coordinates
};

// Structure to represent a mesh
struct Mesh {
    std::vector<Vertex> vertices;  // Array of vertices
    std::vector<GLuint> indices;   // Array of indices for indexed drawing
    GLuint VAO;                    // Vertex Array Object identifier
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

#endif // BLENDER_RENDERING_H
