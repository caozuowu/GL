//
//  glutHerald.h
//  exlib
//
//  Created by  zuowu on 2021/1/5.
//

#ifndef glutHerald_h
#define glutHerald_h

#include <GLUT/GLUT.h>

namespace exlib {

class GlutHerald {
public:
    GlutHerald();
    static GlutHerald * getInstance();
};


}

#endif /* glutHerald_h */
