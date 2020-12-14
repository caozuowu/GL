//
//  execrise_1.3.1.cpp
//  execrise_1.3.1
//
//  Created by zuowu on 2020/12/2.
//

#include "exlib.h"

#include <OpenGL/gl3.h>
#include <GLUT/GLUT.h>

void display(){
    
}

void close() {
    exit(0);
}


int main(int argc, char ** argv) {
//    exlib::Shader(GL_VERTEX_SHADER, "");
    
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 600);
    glutCreateWindow("");
    
    exlib::Shader(GL_VERTEX_SHADER, "shader/shader.vs");
    
    glutDisplayFunc(display);
    glutWMCloseFunc(close);
    
    glutMainLoop();
    
    return 0;
}
