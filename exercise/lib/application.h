//
//  application.h
//  exlib
//
//  Created by  zuowu on 2020/12/24.
//

#ifndef application_h
#define application_h

#include "window.h"
#include <thread>

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

//typedef struct{
//    int threadid;
//    void callback();
////    LoopThread();
//}LoopThread;

class LoopThread {
public:
    LoopThread(){
//        std::thread t(1,1);
        _thread = std::thread();
        _thread.get_id();
    }
    std::thread _thread;
    void loopThreadFunc();
};


}

#endif /* application_h */
