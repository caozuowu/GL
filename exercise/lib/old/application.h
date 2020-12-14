//
//  application.h
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#ifndef application_h
#define application_h

#include <stdio.h>
#include "window.h"



namespace exlib {

class Application;
class ApplicationDelegate;

int ApplicationMain(int argc, char **  argv, ApplicationDelegate * delegate, Window * mainWindow);

class ApplicationDelegate {
public:
    virtual void onApplicationCreate(Application * app) = 0;
    virtual void onApplicationDestory() = 0;
};

class Application {
public:
    static Application * getApplicationInstance();
    Application(int argc, char ** argv, ApplicationDelegate * delegate, Window * mainWindow);
    
    Window * currentWindow();
    
    void mainLoop();
private:
    Window * _currentWindow;
    ApplicationDelegate * _delegate;

};



}

#endif /* application_h */
