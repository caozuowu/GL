//
//  shader.h
//  exlib
//
//  Created by zuowu on 2020/12/2.
//

#ifndef shader_h
#define shader_h

#include <iostream>
#include <vector> 
using namespace std;

namespace exlib {

class Shader;
class ShaderProgram;

class Shader {
public:
    Shader(int type, std::string str);
    ~Shader();
    
    int index();
private:
    int _gl_index;
    
};

class ShaderProgram {
public:
    void attachShader(Shader * p, ...);
    ShaderProgram();
    ShaderProgram(Shader * p, ...);
    void use();
private:
    int _gl_index;
    vector<Shader> _shaders;
};

}

#endif /* shader_h */
