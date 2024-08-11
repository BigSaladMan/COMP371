// rendering.h

#ifndef RENDERING_H
#define RENDERING_H

#include <GL/glew.h>
#include <string>

extern const char* vertexShaderSource;
extern const char* fragmentShaderSource;

GLuint createShaderProgram();
void checkCompileErrors(GLuint shader, std::string type);
struct Mesh {
    GLuint VAO, VBO, EBO;
    size_t indexCount;
};

Mesh loadOBJModel(const std::string& filepath);

#endif // RENDERING_H
