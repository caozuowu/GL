
#### 着色器语法

    #version 版本号
    in 数据类型 变量名;
    in 数据类型 变量名;
    out 数据类型 变量名;
    uniform 数据类型 变量名;

 * in表示从上一个阶段输入的数据
 * out表示这个阶段需要输出的数据 
 * uniform表示全局的数据
 
 #### 着色器之间数据互通
 
    #version 330 core
    layout (locatuion = 0) in vec3 aColor;
    out vec3 ourColor;
    void main(){
        gl_Position = vec4(aPos, 1.0);
        outColor = vec3(0.5f, 0.0f, 0.0f);
    }
    
    #version 330 core
    out vec4 FragColor;
    in vec3 ourColor;
    void main(){
        FragColor = vec4(outColor, 1.0f);
    }

  * 上一个阶段的输出变量就会成为下一个阶段的输入变量，只要变量名相同就行了。注意，必须要相同变量名，否则接收不到
  * 定义成uniform方式的变量就是全局的变量，可以在应用中访问，不过需要一些特殊的访问方式
  
        float greenValue = 1.0f;
        int outColorLoaction = glGetUniformLoaction(shaderProgram, "shader中定义id");
        glUseProgram(shaderProgram);
        glUniform4f(outColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
  
