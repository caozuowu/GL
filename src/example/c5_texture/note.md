
#### 映射方式

    [0.1   1.1 
     0.0   1.0]
     
* 需要再顶点数据中添加一个而纹理坐标数据,将纹理上的元素映射到顶点上

#### 环绕方式
 * 超出[0,0] - [1,1] 范围,默认重新绘制纹理
 * 其他选择方案
   * GL_REPEAT: 默认,重复纹理图片
   * GL_MIRRORED_REPEAT：类似于默认方案，不过每次重复的时候进行镜像重复 (超出部分方向相反)
   * GL_CLAMP_TP_EDGE：将坐标限制在0到1之间。超出的坐标会重复绘制边缘的像素，变成一种扩展边缘的图
   * GL_CLAMP_TO_BORDER：超出的坐标将会被绘制成用户指定的边界颜色
   * [图片链接](https://upload-images.jianshu.io/upload_images/7822237-f3888cfbd0b2c3b3.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/517)
 * 环绕方式设定:
            
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_GL_PREPEAT);    //横坐标
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_GL_PREPEAT);    //纵坐标
        
 *  GL_CLAMP_TO_BORDER 之后指定边界

        float borderColor[] = [1.0f, 1.0f, 0.0f, 1.0f];
        glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, borderColor);
        
#### 纹理过滤
 * 计算文字图片上像素和坐标关系,一张低分辨率的纹理图,需要用到一个非常大的物体上时很明显
 * GL_NEARTST : 最近点过滤.指的是纹理坐标最靠近哪个纹素,就用哪个纹素.OpenGL默认,速度最快,效果最差
 * GL_LINEAR:（双）线性过滤.指的是纹理坐标位置附近的几个纹素值进行某种插值计算之后的结果.最广泛,效果一般,速度较快
 * 设定
        
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);   //缩小 GL_NEARTST
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_FILTER, GL_LINEAR);    //放大 GL_LINEAR
        
#### Mipmaps - 多级渐进纹理
* 太远的物体我们看不清楚,非常精细没有意义,而且使用原始贴图计算映射起来太麻烦,所以,我们使用一种mipmaps的方式来进行处理.所谓的mipmaps,就是一系列的纹理图片,每一张纹理图的大小都是前一张的1/4,直到剩最后一个像素为止
* [图片链接](https://upload-images.jianshu.io/upload_images/7822237-faab880c9e67b010.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/300)
* 设定 : `glGenerateMipmaps`
* 结合纹理过滤,有了四种不同的过滤方案
   * GL_NEAREST_MIPMAP_NEAREST：采用最近的mipmap图,在纹理采样的时候使用最近点过滤采样
   * GL_LINEAR_MIPMAP_NEAREST：采用最近的mipmap图,纹理采样的时候使用线性过滤采样
   * GL_NEAREST_MIPMAP_LINEAR：采用两张mipmap图的线性插值纹理图,纹理采样的时候采用最近点过滤采样
   * GL_LINEAR_MIPMAP_LINEAR：采用两张mipmap图的线性插值纹理图,纹理采样的时候采用线性过滤采样
   * 设定:
   
            glTexParmeteri(GL_TEXTURE2D, GL_TEXTURE_MIN_FILTER, GL_LINER_MIPMAP_LINEAR);
            glTexParmeteri(GL_TEXTURE2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            
#### 顶点数据

    float vertices[] = {
        //位置                    // 颜色                    //纹理坐标
         0.5f,     0.5f,    0.0f,    1.0f,    0.0f,    0.0f,    1.0f,    1.0f,    //右上角
         0.5f,    -0.5f,    0.0f,    0.0f,    1.0f,    0.0f,    1.0f,    0.0f,    //右下角
        -0.5f,    -0.5f,    0.0f,    0.0f,    0.0f,    1.0f,    0.0f,    0.0f,    //左下角
        -0.5f,     0.5f,    0.0f,    1.0f,    1.0f,    0.0f,    0.0f,    1.0f     //左上角
    };
    
 * 颜色属性
 
        //着色器, 顶点个数 , 数据类型 , 数据是否要被规范化 , 属性跨度, 偏移
        glVerTexAttribPointer(1,3,GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)3*sizeof(float)));
        
 * 纹理属性
 
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FLASE, 8*sizeof(float), (void*)6*sizeof(float)));
        glEnableVertexAttribArry(2);
   
   
        
        
        
