//
//  shader.cpp
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#include "shader.h"
#include <OpenGL/gl3.h>

using namespace exlib;

ShadProgram::ShadProgram() {
    _index = glCreateProgram();
}

void ShadProgram::attachShader(Shader * shader) {
    glAttachShader(_index, shader->getIndex());
}

void ShadProgram::link() {
    
    glLinkProgram(_index);
    
    int success;
    char infoLog[512];
    glGetProgramiv(_index, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(_index, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
}



Shader::Shader(int type, const char * str) {
    
    std::ifstream file;
    const char * source;
    
    try {
        
        file.open(str);
        std::stringstream stream;
        stream << file.rdbuf();
        file.close();
        source = stream.str().c_str();
        
    } catch (std::ifstream::failure e) {
        
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        std::cout << "ERROR::SHADER:: 加载文件shader失败, 尝试字符串加载" << std::endl;

        source = str;
    }
    
    
    _index = glCreateShader(type);
    glShaderSource(_index, 1, &source, nullptr);
    glCompileShader(_index);
    
    int success;
    char infoLog[512];
    glGetShaderiv(_index, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(_index, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }
}

Shader::~Shader() {
    glDeleteShader(_index);
}

int Shader::getIndex() {
    return _index;
}

void ShadProgram::use() {
    glUseProgram(_index);
}
