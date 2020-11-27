//
//  application.h
//  exlib
//
//  Created by zuowu on 2020/11/27.
//

#ifndef application_h
#define application_h

#include <stdio.h>
#include "window.h"

namespace exlib {

    struct glVersion {
        int major;
        int minor;
    };

    class Application {
    public:
        Application(int gl_version_major, int gl_version_minor);
        ~Application();
   
         Window * window;
        
    private:
        glVersion version;
    };
}



#endif /* application_h */
