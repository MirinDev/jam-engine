#ifndef TEXTURE2D_H_
#define TEXTURE2D_H_

#include "Utils.h"
#include "Shader.h"

namespace Jam
{
    class Texture2D
    {
        public:
            Texture2D(std::string path);
            ~Texture2D();

            void aloc(Shader* shader, std::string uniform);

            int width, height, aloc_id;

            GLuint get_id(){return ID;};
        
        private:
            GLuint ID;
    };

    void bind_texture(Texture2D* texture);
}

#endif