#ifndef VEC3_H_
#define VEC3_H_

#include <iostream>
#include <cmath>

namespace Jam
{
    namespace Math
    {
        typedef union vec3_t
        {
            struct{float value[3];};
            struct{float x, y, z;};
            struct{float r, g, b;};
            struct{float s, t, p;};

            vec3_t(float x, float y, float z);
            vec3_t(float value);

            vec3_t operator*(float value);
            vec3_t operator*(vec3_t vector);
            vec3_t operator/(float value);
            vec3_t operator/(vec3_t vector);
            
            vec3_t operator+(vec3_t vector);
            vec3_t operator-(vec3_t vector);
        } vec3;
    }
}

#endif