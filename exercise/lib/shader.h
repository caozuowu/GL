//
//  shader.hpp
//  exercise
//
//  Created by zuowu on 2020/11/27.
//

#ifndef shader_h
#define shader_h

#include <stdio.h>

namespace exlib {
    class Shader {
    public:
        Shader();
        Shader(int type, char ** string);
        ~Shader();
    private:
        int _index;
        int _type;
        char ** _string;

    };
}


#endif /* shader_hpp */
