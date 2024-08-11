#ifndef RENDERING_H
#define RENDERING_H

#include <GL/glew.h>
#include <string>

GLuint createShaderProgram();
GLuint createTriangleVAO();
void checkCompileErrors(GLuint shader, std::string type);

#endif // RENDERING_H
