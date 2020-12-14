//
//  shader.h
//  exlib
//
//  Created by zuowu on 2020/12/2.
//

#ifndef shader_h
#define shader_h

#include <iostream>

namespace exlib {

class Shader;
class ShaderProgram;

class Shader {
public:
    Shader(int type, std::string str);
    ~Shader();
private:
    int _gl_index;
    
};

class ShaderProgram {
public:
    ShaderProgram(Shader shader, ...);
};

}

#endif /* shader_h */
