//
//  application.cpp
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#include "application.h"
#include <GLUT/GLUT.h>

using namespace exlib;

Application * instance = nullptr;

int exlib::ApplicationMain(int argc, char **  argv, ApplicationDelegate * delegate,  Window * mainWindow) {
    instance = new Application(argc, argv, delegate, mainWindow);
    instance->mainLoop();
    return 0;
}

Application * Application::getApplicationInstance() {
    return instance;
}

Application::Application(int argc, char **argv, ApplicationDelegate * delegate, Window * mainWindow){
    _delegate = delegate;
    _currentWindow = mainWindow;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA|GLUT_DEPTH);
}


Window * Application::currentWindow() {
    return _currentWindow;
}

void Application::mainLoop(){
    glutMainLoop();
}

