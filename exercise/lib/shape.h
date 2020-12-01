//
//  shape.h
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#ifndef shape_h
#define shape_h

#include <OpenGL/gl3.h>

namespace exlib {

class Shape {
    

public:
    
    Shape(float * vertices, int size_vertices, unsigned int * indices, int size_indices);
    ~Shape();
    
    void setVAO(float * vertices, int size_vertices);
    void setEBO(unsigned int * indices, int size_indices);
    
    void drawElement(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
    void drawArray(GLenum mode, GLint first, GLsizei count);
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    
private:
    int _index;
//    float * vertices;
//    int * indices;
    
    
};

}


#endif /* shape_h */
