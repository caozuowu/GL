//
//  c3_element_caching.cpp
//  c3_element_caching
//
//  Created by zuowu on 2018/6/22.
//  Copyright © 2018年 zuowu. All rights reserved.
//

/*
 * 元素缓存对象（Element Buffer Object，简称EBO）
 * 显示一个矩形？使用三角形图元的话，就需要将矩形分为两个三角形，这两个三角形拥有两个相同的顶点。
 * 但是，这样一来，我的顶点数组中就需要6个顶点数据，这样太浪费了，3D显示本来就非常耗资源，再弄点冗余的数据无异于雪上加霜。
 * 于是，元素缓存对象横空出世，解决了冗余数据的问题。
 */

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height){
    glViewport(0, 0, width, height);
}
void processInput(GLFWwindow *window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

const char * vertexShaderSource = "                     \n\
#version 330 core                                       \n\
layout (location = 0) in vec3 aPos;                     \n\
void main()                                             \n\
{                                                       \n\
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);    \n\
}                                                       \0\
";

const char* fragmentShaderSource = "            \n\
#version 330 core                               \n\
out vec4 FragColor;                             \n\
void main()                                     \n\
{                                               \n\
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);   \n\
}                                               \0\
";

float rectVertices[] = {
     0.5f,  0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
    -0.5f, -0.5f, 0.0f,
    -0.5f,  0.5f, 0.0f
};

//公用两个点的两个三角形
unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};

int main(int argc, const char * argv[]){
    std::cout<<"chapter 3 element caching"<<std::endl;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow * window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ch3 element caching", NULL, NULL);
    if (window == NULL) {
        std::cout<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout<<"Fail to initialize GLAD"<<std::endl;
        return -1;
    }
    
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    
    int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    
    int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(rectVertices), rectVertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);
    glEnableVertexAttribArray(0);
    
    //需要VBO设置完成了之后再设置
    unsigned int EBO;
    //获取ID
    glGenBuffers(1, &EBO);
    //绑定到 OpenGL
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    //指定索引数组 GL_ELEMENT_ARRAY_BUFFER 指定使用 EBO
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        
        glBindVertexArray(VAO);
        /*
         * 绘制VBO 使用 glDrawArray
         * 绘制EBO 使用 glDrawElement
         * 绘图类型 , 索引数量 , 所以数据类型 , 外部位置指示,索引在EBO中为0
         */
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}

















