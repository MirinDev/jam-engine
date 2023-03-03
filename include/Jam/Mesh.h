#ifndef MESH_H_
#define MESH_H_

#include "Utils.h"
#include "Vertices.h"
#include "Texture2D.h"
#include "Shader.h"

namespace Jam
{
    class Mesh
    {
        public:
            Mesh(std::vector<vert> vertices, std::vector<unsigned short> indices);
            ~Mesh();

            void add_texture(Texture2D* texture);

            void render();
        
        private:
            //GLuint buffers[2];
            GLuint VAO;
            int vert_size;

            std::vector<Texture2D*> textures;
    };
}

#endif