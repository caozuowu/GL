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
    void mainLoop();
    
    WindowChain * getWindowChain();
    
private:
    
    Application(int argc, char ** argv);
    
    Window * _mainWindow;
    
    WindowChain * _windowChain;

};


}

#endif /* application_h */
