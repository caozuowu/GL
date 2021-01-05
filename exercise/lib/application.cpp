//
//  application.cpp
//  exlib
//
//  Created by  zuowu on 2020/12/24.
//

#include "application.h"
#include <GLUT/GLUT.h>
#include <iostream>
#include <sys/time.h>

using namespace exlib;

void APP_GLUT_DISPLAY_FUNC() {
    
    int index = glutGetWindow();
    Window * w = Application::getInstance()->getWindow(index);
    w->onDisplay();
}

void APP_GLUT_WMCLOSE_FUNC() {
    
    int index = glutGetWindow();
    Window * w = Application::getInstance()->getWindow(index);
    w->onClose();
    
}

static Application * _s_instance = NULL;

int exlib::ApplicationMain(int argc, char ** argv, Window * window) {
    
    _s_instance = new Application(argc, argv);
    _s_instance->getWindowChain()->push(window->init());
    _s_instance->initGlutFunc();
    _s_instance->mainLoop();
    
    return 0;
}

Application * Application::getInstance() {
    return _s_instance;
}

Window * Application::getWindow(int index) {
    return _windowChain->getWindow(index);
}

Application:: Application(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    _windowChain = new WindowChain();
    _FPS = 10;
}

void Application::setFPS(int fps) {
    _FPS = fps;
}

void Application::initGlutFunc() {
    glutDisplayFunc(APP_GLUT_DISPLAY_FUNC);
    glutWMCloseFunc(APP_GLUT_WMCLOSE_FUNC);
}

WindowChain * Application::getWindowChain(){
    return _windowChain;
}

void Application::mainLoop() {
    glutMainLoop();
    float cyclelength = 1.0f/(float)_FPS * 1000;
    
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    int64_t start = tv.tv_sec * 1000 + tv.tv_usec / 1000;
    
}
