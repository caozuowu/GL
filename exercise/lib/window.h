//
//  window.h
//  exlib
//
//  Created by zuowu on 2020/11/27.
//

#ifndef window_h
#define window_h

#include <stdio.h>
#include <map>
#include <GLFW/glfw3.h>

namespace exlib {

    class WindowDelegate {
    public:
        virtual void windowRenderFunction() = 0;
        virtual void windowCloseFunction() = 0;
        virtual void windowChangeSizeFunction() = 0;
    };

    class Window {
    public:
        Window(float width, float height, const char * title);
        ~Window();
        static Window * careteWindow(float width, float height, const char * title);
        void mainLoop();
        
        WindowDelegate * delegate;
    private:
        float width;
        float height;
        GLFWwindow * _window;
        
        static void framebuffer_size_callback(GLFWwindow* window, int width, int height);
        
    };
}



#endif /* window_h */
