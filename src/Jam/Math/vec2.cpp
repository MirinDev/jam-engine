#include <Jam/Math/vec2.h>
using namespace std;
using namespace Jam::Math;

vec2_t::vec2_t(float value)
{
    for (int i = 0; i < 2; i++)
        this->value[i] = value;
}

vec2_t::vec2_t(float x, float y)
{
    this->x = x;
    this->y = y;
}

vec2_t vec2_t::operator*(float value)
{
    vec2_t vec = vec2_t(0.0f);
    
    for (int i = 0; i < 2; i++)
        vec.value[i] = this->value[i] * value;
    
    return vec;
}

vec2_t vec2_t::operator*(vec2_t vector)
{
    vec2_t vec = vec2_t(0.0f);
    
    for (int i = 0; i < 2; i++)
        vec.value[i] = this->value[i] * vector.value[i];
    
    return vec;
}

vec2_t vec2_t::operator/(float value)
{
    vec2_t vec = vec2_t(0.0f);
    
    for (int i = 0; i < 2; i++)
        vec.value[i] = this->value[i] / value;
    
    return vec;
}

vec2_t vec2_t::operator/(vec2_t vector)
{
    vec2_t vec = vec2_t(0.0f);
    
    for (int i = 0; i < 2; i++)
        vec.value[i] = this->value[i] / vector.value[i];
    
    return vec;
}

vec2_t vec2_t::operator+(vec2_t vector)
{
    vec2_t vec = vec2_t(0.0f);
    
    for (int i = 0; i < 2; i++)
        vec.value[i] = this->value[i] + vector.value[i];
    
    return vec;
}

vec2_t vec2_t::operator-(vec2_t vector)
{
    vec2_t vec = vec2_t(0.0f);
    
    for (int i = 0; i < 2; i++)
        vec.value[i] = this->value[i] - vector.value[i];
    
    return vec;
}