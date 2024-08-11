#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "transformations.h" // For transformation functions
#include "blender_rendering.h" 

// Function to apply transformations and render the mesh
void renderMesh(const Mesh& mesh, GLuint shaderProgram) {
    // Bind the shader program
    glUseProgram(shaderProgram);

    // Create transformation matrices using transformation utility functions
    glm::mat4 model = glm::mat4(1.0f); // Identity matrix

    // Apply translation
    model = createTranslationMatrix(glm::vec3(0.0f, 0.0f, -5.0f)); // Translate 5 units along z-axis

    // Apply rotation
    model = createRotationMatrix(glm::radians(45.0f), glm::vec3(0.0f, 1.0f, 0.0f)); // Rotate 45 degrees around y-axis

    // Apply scaling
    model = createScalingMatrix(1.0f); // Uniform scaling by factor of 1

    // Pass the matrices to the shader
    GLint modelLoc = glGetUniformLocation(shaderProgram, "model");
    GLint viewLoc = glGetUniformLocation(shaderProgram, "view");
    GLint projectionLoc = glGetUniformLocation(shaderProgram, "projection");

    // Assuming view and projection matrices are set elsewhere
    glm::mat4 view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(projectionLoc, 1, GL_FALSE, glm::value_ptr(projection));

    // Bind the VAO and draw the mesh
    glBindVertexArray(mesh.VAO);
    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(mesh.indices.size()), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}
