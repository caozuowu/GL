// triangles.cpp : 定义控制台应用程序的入口点。
//

//#include "stdafx.h"
#include <iostream>
using namespace std;
#include <vgl.h>
#include "loadShaders.h"

enum VAO_IDs
{
	Triangles,
	NumVAOs
};
enum Buffer_IDs
{
	ArrayBuffer,
	NumBuffers
};

enum Attrib_IDs
{
	VPosition = 0
};

GLuint VAOs[NumVAOs];
GLuint Buffers[NumBuffers];

const GLuint NumVertices = 6;

void init(void)
{
	glGenVertexArrays(NumVAOs,VAOs);
	glBindVertexArray(VAOs[Triangles]);

	GLfloat vertices[NumVertices][2] = {
		{-0.90f,-0.90f},
		{ 0.85f,-0.90f},
		{-0.90f, 0.85f},
		{ 0.90f,-0.85f},
		{ 0.90f, 0.90f},
		{-0.85f, 0.90f}
	};

	glGenBuffers(NumBuffers,Buffers);
	glBindBuffer(GL_ARRAY_BUFFER,Buffers[ArrayBuffer]);
	glBufferData(GL_ARRAY_BUFFER,sizeof(vertices),vertices,GL_STATIC_DRAW);

	ShaderInfo shaders[] = {
		{GL_VERTEX_SHADER,"triangles.vert"},
		{GL_FRAGMENT_SHADER,"triangles.frag"},
		{GL_NONE,NULL},
	};

	GLuint program = LoadShaders(shaders);

	glUseProgram(program);

	glVertexAttribPointer(VPosition,2,GL_FLOAT,GL_FALSE,0,BUFFER_OFFSET(0));
	glEnableVertexAttribArray(VPosition);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBindVertexArray(VAOs[Triangles]);
	glDrawArrays(GL_TRIANGLES,0,NumVertices);
	glFlush();
}
int main(int argc, char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGBA);
	glutInitWindowSize(512,512);
	glutInitContextVersion(3,0);
	glutInitContextProfile(GLUT_CORE_PROFILE);
	glutCreateWindow(argv[0]);

	if (glewInit()){
		cerr<<"Unable to initialize GLEW ... exiting111111111111111111"<<endl;
		exit(EXIT_FAILURE);
	}

	init();
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}