//
//  application.c
//  exlib
//
//  Created by zuowu on 2020/11/27.
//

#include "application.h"

using namespace exlib;

Application::Application(int gl_version_major, int gl_version_minor) {
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, gl_version_major);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, gl_version_minor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
#ifndef __APPLE__
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }
#endif
    
    window = new Window(800, 600, "");

}

Application::~Application(){
    
}
