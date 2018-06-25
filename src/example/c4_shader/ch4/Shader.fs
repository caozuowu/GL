//
//  Shader.fs
//  GL
//
//  Created by zuowu on 2018/6/25.
//  Copyright © 2018年 zuowu. All rights reserved.
//

#version 330 core
out vec4 FragColor;
in vec3 ourColor;
void main(){
    FragColor = vec4(ourColor, 1.0f);
}


