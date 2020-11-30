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
    Shape(const float * vertices, int * indices);
    ~Shape();
    
    void draw(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices);
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    
private:
//    float * vertices;
//    int * indices;
    
    
};

}


#endif /* shape_h */
