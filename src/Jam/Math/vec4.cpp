#include <Jam/Math/vec4.h>
using namespace std;
using namespace Jam::Math;

vec4_t::vec4_t(float value)
{
    for (int i = 0; i < 4; i++)
        this->value[i] = value; 
}

vec4_t::vec4_t(float x, float y, float z, float w)
{
    this->x = x;
    this->y = y;
    this->z = z;
    this->w = w;
}

vec4_t vec4_t::operator*(mat4 matrix)
{
    vec4_t vec = vec4_t(0.0f);

    for (int i = 0; i < 4; i++)
        vec.value[i] = this->x * matrix.v4x4[i][0] + this->y * matrix.v4x4[i][1]
                     + this->z * matrix.v4x4[i][2] + this->w * matrix.v4x4[i][3];

    return vec;
}

vec4_t vec4_t::operator*(float value)
{
    vec4_t vec = vec4_t(0.0f);
    
    for (int i = 0; i < 4; i++)
        vec.value[i] = this->value[i] * value;
    
    return vec;
}

vec4_t vec4_t::operator*(vec4_t vector)
{
    vec4_t vec = vec4_t(0.0f);
    
    for (int i = 0; i < 4; i++)
        vec.value[i] = this->value[i] * vector.value[i];
    
    return vec;
}

vec4_t vec4_t::operator/(float value)
{
    vec4_t vec = vec4_t(0.0f);
    
    for (int i = 0; i < 4; i++)
        vec.value[i] = this->value[i] / value;
    
    return vec;
}

vec4_t vec4_t::operator/(vec4_t vector)
{
    vec4_t vec = vec4_t(0.0f);
    
    for (int i = 0; i < 4; i++)
        vec.value[i] = this->value[i] / vector.value[i];
    
    return vec;
}

vec4_t vec4_t::operator+(vec4_t vector)
{
    vec4_t vec = vec4_t(0.0f);
    
    for (int i = 0; i < 4; i++)
        vec.value[i] = this->value[i] + vector.value[i];
    
    return vec;
}

vec4_t vec4_t::operator-(vec4_t vector)
{
    vec4_t vec = vec4_t(0.0f);
    
    for (int i = 0; i < 4; i++)
        vec.value[i] = this->value[i] - vector.value[i];
    
    return vec;
}