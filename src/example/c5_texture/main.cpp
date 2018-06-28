//
//  main.cpp
//  c5_texture
//
//  Created by zuowu on 2018/6/27.
//  Copyright © 2018年 zuowu. All rights reserved.
//

#include <iostream>
#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include "Shader.h"
#define STB_IMAGE_IMPLEMENTATION
#include <stb-master/stb_image.h>

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

float vertices[] = {
    //位置                    // 颜色                    //纹理坐标
     0.5f,     0.5f,    0.0f,    1.0f,    0.0f,    0.0f,    1.0f,    1.0f,    //右上角
     0.5f,    -0.5f,    0.0f,    0.0f,    1.0f,    0.0f,    1.0f,    0.0f,    //右下角
    -0.5f,    -0.5f,    0.0f,    0.0f,    0.0f,    1.0f,    0.0f,    0.0f,    //左下角
    -0.5f,     0.5f,    0.0f,    1.0f,    1.0f,    0.0f,    0.0f,    1.0f     //左上角
};

unsigned int indices[] = {
    0, 1, 3,
    1, 2, 3
};
int main(int argc, const char * argv[]){
    std::cout<<"chapter 5 texture"<<std::endl;
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow * window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "ch5_texture", NULL, NULL);
    if (window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
    
    //获取最大属性数量
    int nrAttributes;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    std::cout << "最大支持的属性数量 : " << nrAttributes << std::endl;
    
    Shader shader("ch5/Shader.vs","ch5/Shader.fs");
    
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    //坐标数据    前三个
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    //颜色数据    中间三个
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    //纹理数据    最后三个
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
    
    //纹理
    unsigned int texture;
    glGenTextures(1, &texture);              //唯一ID创建 第一个参数是要创建的纹理数量，后面的参数就是保存这么多数量的整型数数组
    glBindTexture(GL_TEXTURE_2D, texture);   //绑定
    
    //过滤方式
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);                       //横坐标  默认重复
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);                       //纵坐标  默认重复
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);     //缩小 mipmap  最近点
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);                   //放大 双线性过滤
    
    int width, height, nrChannels;   //纹理属性  宽,高,颜色通道
    //OpenGL期待原点（0,0）位于左下角,而通常一张图片的原点位于左上角,stb库早就已经为我们准备了解决方案 解决上下颠倒
    stbi_set_flip_vertically_on_load(true);
    //读取图片
    unsigned char * data = stbi_load("ch5/beauty.jpg", &width, &height, &nrChannels, 0);
    if (data) {
        /* 创建纹理
         * 参数一：指定目标纹理。GL_TEXTURE_2D就表示当前的操作会对绑定的2D纹理产生作用（GL_TEXTURE_1D和GL_TEXTURE_3D里的东西就不会受影响）
         * 参数二：mipmap层级。我们之后会调用glGenerateMipmap来创建，这里只需要创建原始图就行了。（或者你也可以手动的一次次调用这个函数来创建，（坏笑~））
         * 参数三：我们需要保存的纹理格式。我们的图片只有RGB信息，所以用GL_RGB格式。
         * 参数四和参数五：纹理图片的宽高。之前保存的那个。
         * 参数六：一定要设置成0（有一些遗留的工作）
         * 参数七和参数八：源图片的格式和数据类型。我们加载的图片中有RGB值，并且以字节的方式保存。所以我们传递了这两个参数。
         * 参数九：加载的图片数据
         * 参数写错 黑图....
         */
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        //创建mipmap
        glGenerateMipmap(GL_TEXTURE_2D);
    }else {
        std::cout << "load image error" << std::endl;
    }
    //加载完毕释放资源
    stbi_image_free(data);
    
    while (!glfwWindowShouldClose(window)) {
        processInput(window);
        
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        shader.use();
        
        /*
         * 这里是一个习惯，上面的操作把属性都保存到了VAO中，这里只需要绑定就可以
         * 如果要显示的东西不同，也只需要在这里绑定不同的东西就可以显示
         */
        glBindTexture(GL_TEXTURE_2D, texture);
        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
        
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glfwTerminate();
    
    return 0;
}



















