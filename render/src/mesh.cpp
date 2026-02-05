#include "../include/mesh.hpp"
#include <glad/glad.h>

using namespace gyoza;

gyoza::Mesh::Mesh(std::vector<Vertex> vertices_, std::vector<unsigned int> indices_): vertices{vertices_}, indices{indices_}
{
    Buffer_data();
}

gyoza::Mesh::Mesh(Primitive primite)
{
    switch(primite)
    {
        case Primitive::CUBE:
            Gen_cube_primitive();
            break;
        case Primitive::SPHERE:
            Gen_sphere_primitive();
            break;
    }

    Buffer_data();
}

void gyoza::Mesh::Draw()
{
    glBindVertexArray(this->vao);
    glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
}

void gyoza::Mesh::Buffer_data()
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

void gyoza::Mesh::Gen_cube_primitive()
{
    this->vertices = {
    {}
    };
}

gyoza::Mesh::~Mesh()
{
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
}
