// OpenGLIntro.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <GL/glew.h>


int main()
{
    // Vertex shader
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
   
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    float verticesTriangle[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int VBO[2], VAO[2], EBO;
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO[0]);
    GLFWwindow* window;


    while (!glfwWindowShouldClose(window)) {
        //processInput(window);
    }

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
