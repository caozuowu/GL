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

int Shader::index() {
    return _gl_index;
}

void ShaderProgram::attachShader(Shader shader) {
    glAttachShader(_gl_index, shader.index());
}

ShaderProgram::ShaderProgram(vector<Shader> a){
    _gl_index = glCreateProgram();
//    attachShader(<#Shader shader#>)
//    _shaders = vector(&a);
    glLinkProgram(_gl_index);
    
    int success;
    char infoLog[512];
    glGetProgramiv(_gl_index, GL_LINK_STATUS, &success);
    if(!success)
    {
        glGetProgramInfoLog(_gl_index, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }
    
    //    glDeleteShader(<#GLuint shader#>)
}

void ShaderProgram::use(){
    glUseProgram(_gl_index);
}

