#include <Jam/Canvas.h>
using namespace std;

void Jam::bind_canvas(Jam::Canvas* canvas)
{
    //
}

using namespace Jam;

Canvas::Canvas(int width, int height)
{
    //
}

Canvas::~Canvas()
{
    //
}

int aloc_id = 0;

void Canvas::aloc(Shader* shader, string uniform)
{
    glActiveTexture(GL_TEXTURE0 + aloc_id);
    shader->send(uniform, aloc_id);
}
