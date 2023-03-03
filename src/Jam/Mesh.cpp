#include <Jam/Mesh.h>
using namespace std;
using namespace Jam;

Mesh::Mesh(vector<vert> vertices, vector<unsigned short> indices)
{
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    GLuint buffers[2];
    glGenBuffers(2, buffers);
    glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);

    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(vert), vertices.data(), GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(sizeof(float) * 3));
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(2, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(sizeof(float) * 5));
    glEnableVertexAttribArray(2);
    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 11 * sizeof(float), (void*)(sizeof(float) * 8));
    glEnableVertexAttribArray(3);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned short), indices.data(), GL_STATIC_DRAW);

    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    glDeleteBuffers(2, buffers);

    vert_size = indices.size();
}

Mesh::~Mesh()
{
    //glDeleteBuffers(2, buffers);
    glDeleteVertexArrays(1, &VAO);
}

void Mesh::add_texture(Texture2D* texture)
{
    textures.push_back(texture);
}

void Mesh::render()
{
    //glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, buffers[1]);
    glBindVertexArray(VAO);

    for(int i = 0; i < textures.size(); i++)
    {
        textures[i]->aloc(get_selected_shader(), "tex" + to_string(i));
        bind_texture(textures[i]);
    }

    glDrawElements(GL_TRIANGLES, vert_size, GL_UNSIGNED_SHORT, 0);

    for(int i = 0; i < textures.size(); i++)
        bind_texture(NULL);
    
    glBindVertexArray(0);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);
    //glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
