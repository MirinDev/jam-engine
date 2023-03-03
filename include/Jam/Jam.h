#ifndef JAM_H_
#define JAM_H_

#include "Utils.h"
#include "Shader.h"
#include "Window.h"
#include "Mesh.h"

#include "Math/vec2.h"
#include "Math/vec3.h"
#include "Math/vec4.h"
#include "Math/mat4.h"
#include "Math/radians.h"

namespace Jam
{
    void open(void);
    void close(void);

    void loadGL(void);

    void set_viewport(int x, int y, int w, int h);
    void set_clear_color(float r, float g, float b, float a);
    void clear(void);

    bool is_running(void);
    void update_events(void);
}

#endif