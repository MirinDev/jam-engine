#ifndef VEC2_H_
#define VEC2_H_

#include <iostream>
#include <cmath>

namespace Jam
{
    namespace Math
    {
        typedef union vec2_t
        {
            struct{float value[2];};
            struct{float x, y;};
            struct{float r, g;};
            struct{float s, t;};

            vec2_t(float x, float y);
            vec2_t(float value);

            vec2_t operator*(float value);
            vec2_t operator*(vec2_t vector);
            vec2_t operator/(float value);
            vec2_t operator/(vec2_t vector);
            
            vec2_t operator+(vec2_t vector);
            vec2_t operator-(vec2_t vector);
        } vec2;
    }
}

#endif