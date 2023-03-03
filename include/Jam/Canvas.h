#ifndef CANVAS_H_
#define CANVAS_H_

#include "Utils.h"
#include "Shader.h"

namespace Jam
{
    class Canvas
    {
        public:

            Canvas(int width, int height);
            ~Canvas();

            void aloc(Shader* shader, std::string uniform);
    };

    void bind_canvas(Canvas* canvas);
}

#endif