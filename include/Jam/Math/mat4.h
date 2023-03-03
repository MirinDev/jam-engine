#ifndef MAT4_H_
#define MAT4_H_

#include <iostream>
#include <cstring>
#include <xmmintrin.h>

#include "vec3.h"

namespace Jam
{
    namespace Math
    {
        typedef struct mat4_t
        {
            union
            {
                float v16[16];
                float v4x4[4][4];
            };
            

            mat4_t(float value);
            mat4_t(float value[16]);
            mat4_t(float value[4][4]);

            mat4_t identity(float value);
            mat4_t translate(vec3_t value);
            mat4_t scale(vec3_t value);
            mat4_t perspective(float aspect, float fov, float near, float far);
            mat4_t ortho(float left, float right, float bottom, float top, float near, float far);

            mat4_t operator*(mat4_t matrix);
            mat4_t operator*=(mat4_t matrix);
        } mat4;
        
    }
}

#endif