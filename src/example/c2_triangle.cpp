//
//  c2_triangle.cpp
//  c2_triangle
//
//  Created by zuowu on 2018/6/22.
//  Copyright © 2018年 zuowu. All rights reserved.
//

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void framebuffer_size_callback(GLFWwindow * window, int width, int height){
    glViewport(0,0, width, height);
}
void processInpuct(GLFWwindow * window){
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;

//顶点着色器
const char * vertexShaderSource = "                     \n\
#version 330 core                                       \n\
layout (location = 0) in vec3 aPos;                     \n\
void main()                                             \n\
{                                                       \n\
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);    \n\
}                                                       \0\
";

//片元着色器
const char* fragmentShaderSource = "            \n\
#version 330 core                               \n\
out vec4 FragColor;                             \n\
void main()                                     \n\
{                                               \n\
    FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);   \n\
}                                               \0\
";

//定点数组
float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
};

int main(int argc, const char * argv[]){
    std::cout<<"chapter 2 triangle"<<std::endl;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           //设定兼容性 MacOS
#endif
    
    GLFWwindow * window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ch2 triangle", NULL, NULL);
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
    
    //编译着色器
    int vertexShader = glCreateShader(GL_VERTEX_SHADER);         //着色器对象
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);  //附加源码
    glCompileShader(vertexShader);                               //编译
    
    //片元着色器
    int framentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(framentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(framentShader);
    
    //连接着色器
    int shaderProgram = glCreateProgram();            //着色器程序对象
    glAttachShader(shaderProgram, vertexShader);      //附加着色器
    glAttachShader(shaderProgram, framentShader);
    glLinkProgram(shaderProgram);                     //连接
    
    //释放着色器
    glDeleteShader(vertexShader);
    glDeleteShader(framentShader);
    
    unsigned int VAO;                  //顶点数组对象ID
    glGenVertexArrays(1, &VAO);        //生成ID
    glBindVertexArray(VAO);            //指定为顶点数组对象

    unsigned int VBO;                                                          //顶点对象缓存ID
    glGenBuffers(1, &VBO);                                                     //生成ID
    glBindBuffer(GL_ARRAY_BUFFER, VBO);                                        //指定为顶点缓存对象
    /*
     * 将顶点数据复制到顶点缓存对象
     * 顶点数据要拷贝的地方,上一句绑定 , 数组大小 , 数组地址 , 显卡用什么方式管理数据 GL_STATIC_DRAW : 不会经常改变,
     */
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    /*
     * 指明顶点格式
     * 顶点属性 着色器代码设定 location = 0 , 顶点个数 , 数据类型 , 数据是否要被规范化 , 属性跨度,x,y,z 三个float 一个点12 字节 , 偏移
     * 操作的是我们刚刚生成并绑定的VBO
     */
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    while (!glfwWindowShouldClose(window)) {
        processInpuct(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glUseProgram(shaderProgram);
        
        //绑定顶点数组对象
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        //更换缓存画布
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    //释放顶点对象
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    return 0;
}










