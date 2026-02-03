#include "render_component.hpp"
#include <glad/glad.h>

gyoza::Render_component::Render_component(unsigned int data_id_): data_id{data_id_}
{
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
}

void gyoza::Render_component::Draw(Shader& shader)
{
    shader.Use();
    unsigned int diffuse_nr = 1;
    unsigned int specular_nr = 1;
    for(unsigned int i{}; i < textures.size(); i++)
    {
        glActiveTexture(GL_TEXTURE0 + i);

        std::string number{};
        std::string name = textures[i].Get_type();
        if(name == "diffuse")
        {
            number = std::to_string(diffuse_nr++);
        }
        else if(name == "specular")
        {
            number = std::to_string(specular_nr++);
        }

        shader.Set_float( ("material.texture_" + name + number).c_str(), i);
        glBindTexture(GL_TEXTURE_2D, textures[i].Get_id());
    }
    glActiveTexture(GL_TEXTURE0);

    glBindVertexArray(this->vao);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void gyoza::Render_component::Buffor_data()
{
    glBindVertexArray(this->vao);

    glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), &vertices[0], GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices[0], GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, tex_cords));

    glBindVertexArray(0);
}
