//
//  execrise_1.3.1.cpp
//  execrise_1.3.1
//
//  Created by zuowu on 2020/12/2.
//

#include <OpenGL/gl3.h>
#include <GLUT/GLUT.h>
#include <exlib.h>

using namespace exlib;


class EXWin : public exlib::Window {
    
    ShaderProgram * program;

public:
    
    EXWin(std::string title, rect rect): exlib::Window(title, rect){
        
    }
    
    void onInit() override {
        std::cout<<"EXWin on onInit"<<std::endl;
        Shader * vs = new Shader(GL_VERTEX_SHADER,"shader/shader.vs");
        Shader * fs = new Shader(GL_FRAGMENT_SHADER,"shader/shader.fs");
        program = new ShaderProgram(vs, fs);
        
        
    }
    
    void onClose() override {
        std::cout<<"EXWin on close"<<std::endl;
        exit(0);
    }
    
    void onDisplay() override {
        
        std::cout<<"EXWin on display"<<std::endl;
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        
        //glUseProgram(shaderProgram);
        program->use();

        float vertices[] = {
             0.5f, -0.5f, 0.0f,  // bottom right
            -0.5f, -0.5f, 0.0f,  // bottom left
             0.0f,  0.5f, 0.0f   // top
        };
        
        unsigned int VBO, VAO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);

        glBindVertexArray(VAO);
        
        glDrawArrays(GL_TRIANGLES, 0, 3);
        
        glutSwapBuffers();
    }
    
    void onRehsape(int width, int height) override {
        glViewport(0, 0, width, height);
    }
    
};

int main(int argc, char ** argv) {
    return ApplicationMain(argc, argv, new EXWin("test", exlib::rect{exlib::point{100,100}, exlib::size{800,600}}));
}
