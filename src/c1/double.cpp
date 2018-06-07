//
//  double.cpp
//  c1_2
//
//  Created by zuowu on 2018/6/7.
//  Copyright © 2018年 zuowu. All rights reserved.
//

#include <GLUT/GLUT.h>

static GLfloat spin = 0.0;

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();
    glRotatef(spin, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 1.0);
    glRectf(-25.0, -25.0, 25.0, 25.0);
    glPopMatrix();
    glutSwapBuffers();
}

void spinDisplay(void) {
    spin += 2.0;
    if (spin > 360.0) {
        spin -= 360;
    }
    glutPostRedisplay();
}

void reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, -1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void mouse (int button, int state, int x, int y) {
    switch (button) {
        case GLUT_LEFT_BUTTON:
            glutIdleFunc(spinDisplay);
            break;
        case GLUT_MIDDLE_BUTTON:
            glutIdleFunc(nullptr);
            break;
        default:
            break;
    }
}

int main(int argc, char ** argv) {
    // insert code here...
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(250, 250);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouse);
    glutMainLoop();
    return 0;
}







