//
//  Shader.vs
//  GL
//
//  Created by zuowu on 2018/6/25.
//  Copyright © 2018年 zuowu. All rights reserved.
//

#version 330 core
layout (location = 0) in vec3 aPos;
out vec3 ourColor;
void main(){
    gl_Position = vec4(aPos, 1.0);
    ourColor = vec3(0.5f, 0.0f, 0.0f);
}


