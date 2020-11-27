//
//  execrise_1.2.2.cpp
//  execrise_1.2.2
//
//  Created by zuowu on 2020/11/27.
//

#include <iostream>
#include "application.h"

class EXWD : public exlib::WindowDelegate {
    
public:
    EXWD(){
        
    }
    ~EXWD(){
        
    }
    virtual void windowRenderFunction(){
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
    }
    void windowCloseFunction(){
        
    }
    void windowChangeSizeFunction(){
        
    }
};

int main(int argc, char ** argv) {
    
    std::cout<<"123"<<std::endl;
    exlib::Application * app = new exlib::Application(3, 3);
    app->window->delegate = new EXWD();
    app->window->mainLoop();
    
    return 0;
}
