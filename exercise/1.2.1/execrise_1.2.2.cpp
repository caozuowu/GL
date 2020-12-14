//
//  execrise_1.2.2.cpp
//  execrise_1.2.2
//
//  Created by zuowu on 2020/11/27.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "exlib.h"

using namespace exlib;

const char *vertexShaderSource = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";
const char *fragmentShaderSource = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";

const char *fragmentShaderSource2 = "#version 330 core\n"
    "out vec4 FragColor;\n"
    "void main()\n"
    "{\n"
    "   FragColor = vec4(0.2f, 0.5f, 1.0f, 1.0f);\n"
    "}\n\0";

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}


int main(int argc, char ** argv) {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow * window = glfwCreateWindow(800, 600, "", NULL, NULL);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    ShadProgram * program1 = new ShadProgram();
    Shader * vertexShader = new Shader(GL_VERTEX_SHADER, vertexShaderSource);
    Shader * fragmentShader = new Shader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    program1->attachShader(vertexShader);
    program1->attachShader(fragmentShader);
    program1->link();
    free(vertexShader);
    free(fragmentShader);
    
    ShadProgram * program2 = new ShadProgram();
    Shader * vertexShader2 = new Shader(GL_VERTEX_SHADER, vertexShaderSource);
    Shader * fragmentShader2 = new Shader(GL_FRAGMENT_SHADER, fragmentShaderSource2);
    program2->attachShader(vertexShader2);
    program2->attachShader(fragmentShader2);
    program2->link();
    free(vertexShader2);
    free(fragmentShader2);
    

    
    float vertices1[] = {
         0.5f,  0.5f, 0.0f,  // top right
         0.5f, -0.5f, 0.0f,  // bottom right
        -0.5f, -0.5f, 0.0f,  // bottom left
    };
    
    float vertices2[] = {
       -0.5f,  0.5f, 0.0f,
        0.5f,  0.5f, 0.0f,
       -0.5f, -0.5f, 0.0f,  // bottom left
    };
    
    Shape * shape1 = new Shape(vertices1, sizeof(vertices1), nullptr, 0);
    Shape * shape2 = new Shape(vertices2, sizeof(vertices2), nullptr, 0);
    
    
//    Shape * shape = new Shape(vertices, sizeof(vertices), indices, sizeof(indices));
    
    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        program1->use();
        shape1->drawArray(GL_TRIANGLES, 0, 3);
        program2->use();
        shape2->drawArray(GL_TRIANGLES, 0, 3);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free(program1);
    free(shape1);
    free(shape2);
    glfwTerminate();
    return 0;
}
