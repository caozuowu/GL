//
//  shader.cpp
//  exercise
//
//  Created by zuowu on 2020/11/27.
//

#include "shader.h"
#ifdef __APPLE__
#include <OpenGL/gl3.h>
#endif

using namespace exlib;

Shader::Shader(){
    
}

Shader::Shader(int type, char ** string) {
    _index = glCreateShader(type);
}

Shader::~Shader(){
    glDeleteShader(_index);
    _string = NULL;
}
