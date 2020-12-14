//
//  window.h
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#ifndef window_h
#define window_h

#include <stdio.h>

namespace exlib {

class Window;
class WindowDelegate;

class WindowDelegate {
    virtual void onWindowCreate() = 0;
};

class Window {
    
public:
    
    Window(int x, int y, int w, int h);
    ~Window();
    void setTitle(const char * title);
    
    virtual void onDisplay();
    virtual void onReshape(int width, int height);
    virtual void onKeyboard(unsigned char key, int x, int y);
    virtual void onMouse(int button, int state, int x, int y);
    virtual void onIdle();
    virtual void onDials(int dial, int value);
    virtual void onWindowStatus(int state);
private:
    
    int _index;
    
    int _width;
    int _height;
    int _pos_x;
    int _pos_y;
    
    const char * _title;
    

    
};

}


#endif /* window_h */
