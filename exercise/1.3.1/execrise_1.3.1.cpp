//
//  execrise_1.3.1.cpp
//  execrise_1.3.1
//
//  Created by zuowu on 2020/12/2.
//

#include <OpenGL/gl3.h>
#include <GLUT/GLUT.h>
#include <exlib.h>

using namespace exlib;


class EXWin : public exlib::Window {

public:
    EXWin(std::string title, rect rect): exlib::Window(title, rect){
        
    }
    void onClose() override {
        std::cout<<"EXWin on close"<<std::endl;
        exit(0);
    }
    
    void onDisplay() override {
        std::cout<<"EXWin on display"<<std::endl;
    }
};

int main(int argc, char ** argv) {
    return ApplicationMain(argc, argv, new EXWin("test", exlib::rect{exlib::point{100,100}, exlib::size{800,600}}));
}
