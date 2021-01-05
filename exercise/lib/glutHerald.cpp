//
//  glutHerald.cpp
//  exlib
//
//  Created by  zuowu on 2021/1/5.
//

#include <iostream>
#include "glutHerald.h"

using namespace exlib;

static GlutHerald * _s_heraldInstance = NULL;

GlutHerald::GlutHerald(){
    
}

GlutHerald * GlutHerald::getInstance() {
    if (!_s_heraldInstance) {
        _s_heraldInstance = new GlutHerald();
    }
    return _s_heraldInstance;
}
