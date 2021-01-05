//
//  application.cpp
//  exlib
//
//  Created by  zuowu on 2020/12/24.
//

#include "application.h"
#include <GLUT/GLUT.h>
#include <iostream>

using namespace exlib;

void APP_GLUT_DISPLAY_FUNC() {
    Application * app = Application::getInstance();
    WindowChain * chain = app->getWindowChain();
    int index = glutGetWindow();
    Window * w = chain->getWindow(index);
    w->onDisplay();
}

void APP_GLUT_WMCLOSE_FUNC() {
    
    Application * app = Application::getInstance();
    WindowChain * chain = app->getWindowChain();
    int index = glutGetWindow();
    Window * w = chain->getWindow(index);
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

Application:: Application(int argc, char ** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
    _windowChain = new WindowChain();
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
}
