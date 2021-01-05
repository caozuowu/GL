//
//  application.h
//  exlib
//
//  Created by  zuowu on 2020/12/24.
//

#ifndef application_h
#define application_h

#include "window.h"

namespace exlib {

int ApplicationMain(int argc, char ** argv, Window * window);

class Application{
    
    friend int ApplicationMain(int argc, char ** argv, Window * window);
    
public:
        
    static Application * getInstance();
    void initGlutFunc();
    void setFPS(int fps);
    void mainLoop();
    
    Window * getWindow(int index);
    WindowChain * getWindowChain();
    
private:
    
    Application(int argc, char ** argv);
    
    Window * _mainWindow;
    
    WindowChain * _windowChain;
    
    int _FPS;

};


}

#endif /* application_h */
