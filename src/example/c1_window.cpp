//
//  c1_window.cpp
//  c1_window
//
//  Created by zuowu on 2018/6/21.
//  Copyright © 2018年 zuowu. All rights reserved.
//

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glad/glad.h>

void framebuffer_size_callback(GLFWwindow * window, int width, int height){
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow * window) {
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, true);
    }
}



int main(int argc, const char * argv[]) {
    
    std::cout<<"chapter 1 window"<<std::endl;
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);                 //OpenGL主版本号
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);                 //OpenGL子版本号
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //使用OpenGL核心模式(可编程渲染管道)
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);           //设定兼容性 MacOS
#endif

    GLFWwindow * window = glfwCreateWindow(1280, 7200, "LearnOpenGL", NULL, NULL);
    if (window == NULL) {
        std::cout<<"Failed to create GLFW window"<<std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window); //创建上下文环境设置为当前主线程的上下文环境
    
    //初始化 glad
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout<<"Failed to initialize GLAD" <<std::endl;
        return -1;
    }
    
    //注册窗口回调函数
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    //渲染循环
    while (!glfwWindowShouldClose(window)) {
        //处理输入时间
        processInput(window);
        //渲染
        glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}



















