#include <Jam/Texture2D.h>
using namespace std;

void Jam::bind_texture(Texture2D* texture)
{
    if(texture == NULL)
        glBindTexture(GL_TEXTURE_2D, 0);
    else
    {
        glBindTexture(GL_TEXTURE_2D, texture->get_id());
    }
}

using namespace Jam;

int _id;

Texture2D::Texture2D(string path)
{
    int channel;

    stbi_set_flip_vertically_on_load(true);
    unsigned char* data = stbi_load(path.c_str(), &width, &height, &channel, 0);

    if (data)
    {
        int type;
        if (channel == 4)
            type = GL_RGBA;
        if (channel == 3)
            type = GL_RGB;
        if (channel == 2)
            type = GL_RG;
        if (channel == 1)
            type = GL_RED;
        
        aloc_id = ++_id;

        glActiveTexture(GL_TEXTURE0 + aloc_id);
        glGenTextures(1, &ID);
        glBindTexture(GL_TEXTURE_2D, ID);

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);	
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        glTexImage2D(GL_TEXTURE_2D, 0, type, width, height, 0, type, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);

        stbi_image_free(data);
    }
}

Texture2D::~Texture2D()
{
    glDeleteTextures(1, &ID);
}

void Texture2D::aloc(Shader* shader, string uniform)
{
    glActiveTexture(GL_TEXTURE0 + aloc_id);
    shader->send(uniform, aloc_id);
}
