#ifndef VEC4_H_
#define VEC4_H_

#include <iostream>
#include <cmath>

#include "mat4.h"

namespace Jam
{
    namespace Math
    {
        typedef union vec4_t
        {
            struct{float value[4];};
            struct{float x, y, z, w;};
            struct{float r, g, b, a;};
            struct{float s, t, p, q;};

            vec4_t(float value);
            vec4_t(float x, float y, float z, float w);

            vec4_t operator*(mat4 matrix);

            vec4_t operator*(float value);
            vec4_t operator*(vec4_t vector);
            vec4_t operator/(float value);
            vec4_t operator/(vec4_t vector);
            
            vec4_t operator+(vec4_t vector);
            vec4_t operator-(vec4_t vector);
        } vec4;
    }
}

#endif