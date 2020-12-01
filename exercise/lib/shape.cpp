//
//  shape.cpp
//  exlib
//
//  Created by zuowu on 2020/11/30.
//

#include "shape.h"
#include <iostream>

using namespace exlib;

Shape::Shape(float * vertices, int size_vertices, unsigned int * indices, int size_indices) {
    
    _index = 1;

    setVAO(vertices, size_vertices);
    setEBO(indices, size_indices);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

}

void Shape::setVAO(float * vertices, int size_vertices) {
    glGenVertexArrays(_index, &VAO);
    glGenBuffers(_index, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, size_vertices, vertices, GL_STATIC_DRAW);

}

void Shape::setEBO(unsigned int *indices , int size_indices) {
    if (indices != NULL && size_indices) {
        glGenBuffers(_index, &EBO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_indices, indices, GL_STATIC_DRAW);
    }
}

void Shape::drawElement(GLenum mode, GLsizei count, GLenum type, const GLvoid *indices) {
    glBindVertexArray(VAO);
    glDrawElements(mode, count, type, indices);
}

void Shape::drawArray(GLenum mode, GLint first, GLsizei count) {
    glBindVertexArray(VAO);
    glDrawArrays(mode, first, count);
}

Shape::~Shape() {
    glDeleteVertexArrays(_index, &VAO);
    glDeleteBuffers(_index, &VBO);
    glDeleteBuffers(_index, &EBO);
}
