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

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void initGlfw(){
    
}

ShadProgram * initShader () {
    ShadProgram * program = new ShadProgram();
    Shader * vertexShader = new Shader(GL_VERTEX_SHADER, vertexShaderSource);
    Shader * fragmentShader = new Shader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    program->attachShader(vertexShader);
    program->attachShader(fragmentShader);
    program->link();
    free(vertexShader);
    free(fragmentShader);
    return program;
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
//    glfwSetWindowPos(window, 0, 0);
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    ShadProgram * program = initShader();
    const float vertices[] = {
        -0.5f, -0.5f, 0.0f, // left
         0.5f, -0.5f, 0.0f, // right
         0.0f,  0.5f, 0.0f  // top
    };
//    Shape * shape = new Shape(vertices, NULL);
    
    unsigned int VBO, VAO;
    //生成
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    //绑定
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    //复制到缓冲区
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0);

    
    while (!glfwWindowShouldClose(window)) {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        program->use();
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
//        shape->draw(GL_TRIANGLES, 0, 3, NULL);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    free(program);
//    free(shape);
    glfwTerminate();
    return 0;
}
