//
//  window.h
//  exlib
//
//  Created by  zuowu on 2020/12/24.
//

#ifndef window_h
#define window_h

#include <string>
#include "ruler.h"

namespace exlib {

class Window{
    
public:
    
    Window(std::string title, rect rect);
    ~Window();
    
    Window * init();
    void display();
    
    Window * prev;
    Window * next;
    
    int glutIndex();
    
    virtual void onClose();
    virtual void onDisplay();
    
private:
    
    rect _rect;
    int _glut_index;
    
    std::string _title;
};

class WindowChain{
public:
    Window * first;
    Window * last;
    WindowChain();
    
    void push(Window * w);
    void pop(Window * w);
    
    Window * getWindow(int index);
};

}

#endif /* window_h */
