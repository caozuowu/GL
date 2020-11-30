//
//  window.cpp
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#include "window.h"
#include "application.h"
#include <GLUT/GLUT.h>
#include <map>

using namespace exlib;

static std::map<Window * , int> windowMap;

void Display(){
    Application::getApplicationInstance()->currentWindow()->onDisplay();
}
void Reshape(int width, int height){
    Application::getApplicationInstance()->currentWindow()->onReshape(width, height);
}
void Keyboard(unsigned char key, int x, int y){
    Application::getApplicationInstance()->currentWindow()->onKeyboard(key, x, y);
}
void Mouse(int button, int state, int x, int y){
    Application::getApplicationInstance()->currentWindow()->onMouse(button, state, x, y);
}
void Idle(){
    
}
void Dials(int dial, int value){
    
}
void WindowStatus(int state){
    
}

Window::Window(int x, int y, int w, int h) {
    
    _width = 800;
    _height = 600;
    _pos_x = 0;
    _pos_y = 0;
    
    glutInitWindowSize(_width, _height);
    glutInitWindowPosition(_pos_x, _pos_y);
    _index = glutCreateWindow("default title");
    windowMap[this] = _index;
    glutSetWindow(_index);
    
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutKeyboardFunc(Keyboard);
    glutMouseFunc(Mouse);
    glutIdleFunc(Idle);
    glutWindowStatusFunc(WindowStatus);
    glutDialsFunc(Dials);

}

void Window::setTitle(const char *title) {
    _title = title;
    glutSetWindow(_index);
    glutSetWindowTitle(title);
}

Window::~Window() {
    glutGet(GLUT_WINDOW_STEREO);
    glutDestroyWindow(_index);
}

void Window::onDisplay(){
   
}
void Window::onReshape(int width, int height){
    glViewport(0, 0, (GLsizei)width, (GLsizei)height);
}
void Window::onKeyboard(unsigned char key, int x, int y){
    
}
void Window::onMouse(int button, int state, int x, int y){
    
}
void Window::onWindowStatus(int state){
    
}
void Window::onDials(int dial, int value){
    
}
void Window::onIdle(){
    
}


