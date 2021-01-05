//
//  window.cpp
//  exlib
//
//  Created by  zuowu on 2020/12/24.
//

#include "window.h"
#include <GLUT/GLUT.h>
#include <iostream>

using namespace exlib;

Window::Window(std::string title, rect rect) {
    _title = title;
    _rect = rect;
    _glut_index = -1;
    
    prev = NULL;
    next = NULL;
}

Window * Window::init() {
    glutInitWindowPosition(_rect.point.x, _rect.point.y);
    glutInitWindowSize(_rect.size.w, _rect.size.h);
    _glut_index = glutCreateWindow(_title.c_str());
    return this;
}

int Window::glutIndex() {
    return _glut_index;
}

Window::~Window(){
    glutDestroyWindow(_glut_index);
}

void Window::onClose() {
    std::cout<<"onClose"<<std::endl;
}

void Window::onDisplay(){
    std::cout<<"onDisplay"<<std::endl;
}

WindowChain::WindowChain() {
    first = NULL;
    last = NULL;
}

void WindowChain::push(Window *w) {
    if (first == NULL) {
        first = last = w;
    }else {
        Window * temp = last;
        last->next = w;
        last = last->next;
        last->prev = temp;
    }
}

void WindowChain::pop(Window *w) {
    if (first == last) {
        Window * temp = last;
        last = last->prev;
        free(temp);
        temp = NULL;
    }else {
        free(first);
        first = last = NULL;
    }
    
}


Window * WindowChain::getWindow(int index) {
    Window * temp = first;
    while (temp) {
        if (temp->glutIndex() == index) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

