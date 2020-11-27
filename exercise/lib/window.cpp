//
//  window.c
//  exlib
//
//  Created by zuowu on 2020/11/27.
//

#include "window.h"
#include <iostream>

using namespace exlib;

static std::map<GLFWwindow *, Window *> windowMap;

Window::Window(float width, float height, const char * title){
        
    _window = glfwCreateWindow(width, height, title, NULL, NULL);
    if (_window == NULL) {
        std::cout << "Failed to create GLFW window" << std::endl;
//        glfwTerminate();
    }
    glfwMakeContextCurrent(_window);
    glfwSetFramebufferSizeCallback(_window, Window::framebuffer_size_callback);
    
    windowMap[_window] = this;

}

Window::~Window(){
    
}

Window * Window::careteWindow(float width, float height, const char * title){
    Window * ref = new Window(width, height, title);
    return ref;
}

void Window::mainLoop() {
    
    while (!glfwWindowShouldClose(_window)) {
        
        if (glfwGetKey(_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
                glfwSetWindowShouldClose(_window, true);
        
        if (delegate)
            delegate->windowRenderFunction();
        
        glfwSwapBuffers(_window);
        glfwPollEvents();
    }
    
    if (delegate)
        delegate->windowCloseFunction();
}

void Window::framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    Window * w = (Window *)windowMap[window];
    if (w && w->delegate) {
        w->delegate->windowChangeSizeFunction();
    }
}
