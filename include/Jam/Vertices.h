#ifndef VERTICES_H_
#define VERTICES_H_

#include "Math/vec2.h"
#include "Math/vec3.h"

namespace Jam
{
    typedef struct vert_t{
        Math::vec3 position;
        Math::vec2 uv;
        Math::vec3 normal;
        Math::vec3 color;
    } vert;
}

#endif