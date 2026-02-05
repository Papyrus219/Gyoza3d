#ifndef GYOZA_MESH_HPP
#define GYOZA_MESH_HPP

#include <vector>
#include "./vertex.hpp"
#include "./primitives.hpp"

namespace gyoza
{

class Mesh
{
public:
    Mesh() = default;
    Mesh(std::vector<Vertex> vertices, std::vector<unsigned int> indices);
    Mesh(Primitive primitive);

    void Draw();

    ~Mesh();
private:
    void Buffer_data();

    void Gen_cube_primitive();
    void Gen_sphere_primitive();

    unsigned int vao{};
    unsigned int vbo{};
    unsigned int ebo{};

    std::vector<Vertex> vertices{};
    std::vector<unsigned int> indices{};
};

}

#endif // GYOZA_MESH_HPP
