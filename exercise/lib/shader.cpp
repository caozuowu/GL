//
//  shader.cpp
//  exlib
//
//  Created by zuowu on 2020/12/2.
//

#include "shader.h"
#include <fstream>
#include <sstream>
#include <OpenGL/gl3.h>

using namespace exlib;

Shader::Shader(int type, std::string str){
    
    std::fstream file;
    
    try {
        
        file.open(str.c_str());
        const char * code;
        
        if (!file) {
            code = str.c_str();
        }else {
            std::stringstream stream;
            stream << file.rdbuf();
            code = stream.str().c_str();
        }
        
        file.close();
        
        glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(_gl_index, 1, &code, NULL);
        glCompileShader(_gl_index);
        
    } catch (std::ifstream::failure e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
    }
    
}

Shader::~Shader() {
    glDeleteShader(_gl_index);
}

ShaderProgram::ShaderProgram(Shader shader, ...) {
    
}
