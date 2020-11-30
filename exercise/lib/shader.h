//
//  shader.h
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#ifndef shader_h
#define shader_h

#include <iostream>

namespace exlib {

class Shader;
class ShadProgram;

class ShadProgram {
public:
    ShadProgram();
    void attachShader(Shader * shader);
    void link();
    void use();
private:
    int _index;
};

class Shader {
public:
    Shader(int type, const char * source);
    ~Shader();
    int getIndex();
private:
    int _index;
};

}

#endif /* shader_h */
