#include <Jam/Math/mat4.h>
using namespace std;
using namespace Jam::Math;

mat4_t::mat4_t(float value)
{
    identity(value);
}

mat4_t::mat4_t(float value[16])
{
    memcpy(v16, value, sizeof(float) * 4);
}

mat4_t::mat4_t(float value[4][4])
{
    memcpy(v4x4, value, sizeof(float) * 4);
}

mat4_t mat4_t::identity(float value)
{
    for (int i = 0; i < 16; i ++) this->v16[i] = 0.0f;
    for (int i = 0; i < 4; i ++) v4x4[i][i] = value;

    return *this;
}

mat4_t mat4_t::translate(vec3_t value)
{
    mat4_t translate_matrix = mat4_t(1.0f);

    for (int i = 0; i < 3; i++)
        translate_matrix.v4x4[i][3] = value.value[i];
    
    *this *= translate_matrix;
    return *this;
}

mat4_t mat4_t::scale(vec3_t value)
{
    mat4_t scale_matrix = mat4_t(1.0f);

    for (int i = 0; i < 3; i++)
        scale_matrix.v4x4[i][i] = value.value[i];
    
    *this *= scale_matrix;
    return *this;
}

mat4_t mat4_t::perspective(float aspect, float fov, float near, float far)
{
    mat4_t perspective_matrix = mat4_t(1.0f);
    float ar = tanf(fov / 2.0f);

    perspective_matrix.v4x4[0][0] = 1.0f / (aspect * ar);
    perspective_matrix.v4x4[1][1] = 1.0f / ar;
    perspective_matrix.v4x4[2][2] = - (far + near) / (far - near);
    perspective_matrix.v4x4[2][3] = - (2.0f * far * near) / (far - near);

    perspective_matrix.v4x4[3][2] = -1.0f;
    perspective_matrix.v4x4[3][3] = 0.0f;

    *this = perspective_matrix;
    return *this;
}

mat4_t mat4_t::ortho(float left, float right, float bottom, float top, float near, float far)
{
    mat4_t ortho_matrix = mat4_t(1.0f);

    ortho_matrix.v4x4[0][0] = 2.0f / (right - left);
    ortho_matrix.v4x4[1][1] = 2.0f / (top - bottom);
    ortho_matrix.v4x4[2][2] = -2.0f / (far - near);

    ortho_matrix.v4x4[0][3] = - (right + left) / (right - left);
    ortho_matrix.v4x4[1][3] = - (top + bottom) / (top - bottom);
    ortho_matrix.v4x4[2][3] = - (far + near) / (far - near);
    
    *this = ortho_matrix;
    return *this;
}


mat4_t mat4_t::operator*(mat4_t matrix)
{
    mat4_t m = mat4_t(1.0f);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            m.v4x4[i][j] = matrix.v4x4[0][j] * this->v4x4[i][0] + matrix.v4x4[1][j] * this->v4x4[i][1]
                         + matrix.v4x4[2][j] * this->v4x4[i][2] + matrix.v4x4[3][j] * this->v4x4[i][3];
        }
    }

    return m;
}

mat4_t mat4_t::operator*=(mat4_t matrix)
{
    *this = *this * matrix;
    return *this;
}
