#include <Jam/Math/vec3.h>
using namespace std;
using namespace Jam::Math;

vec3_t::vec3_t(float value)
{
    for (int i = 0; i < 3; i++)
        this->value[i] = value; 
}

vec3_t::vec3_t(float x, float y, float z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

vec3_t vec3_t::operator*(float value)
{
    vec3_t vec = vec3_t(0.0f);
    
    for (int i = 0; i < 3; i++)
        vec.value[i] = this->value[i] * value;
    
    return vec;
}

vec3_t vec3_t::operator*(vec3_t vector)
{
    vec3_t vec = vec3_t(0.0f);
    
    for (int i = 0; i < 3; i++)
        vec.value[i] = this->value[i] * vector.value[i];
    
    return vec;
}

vec3_t vec3_t::operator/(float value)
{
    vec3_t vec = vec3_t(0.0f);
    
    for (int i = 0; i < 3; i++)
        vec.value[i] = this->value[i] / value;
    
    return vec;
}

vec3_t vec3_t::operator/(vec3_t vector)
{
    vec3_t vec = vec3_t(0.0f);
    
    for (int i = 0; i < 3; i++)
        vec.value[i] = this->value[i] / vector.value[i];
    
    return vec;
}

vec3_t vec3_t::operator+(vec3_t vector)
{
    vec3_t vec = vec3_t(0.0f);
    
    for (int i = 0; i < 3; i++)
        vec.value[i] = this->value[i] + vector.value[i];
    
    return vec;
}

vec3_t vec3_t::operator-(vec3_t vector)
{
    vec3_t vec = vec3_t(0.0f);
    
    for (int i = 0; i < 3; i++)
        vec.value[i] = this->value[i] - vector.value[i];
    
    return vec;
}