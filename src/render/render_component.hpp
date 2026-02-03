#ifndef GYOZA_RENDER_COMPONENT_HPP
#define GYOZA_RENDER_COMPONENT_HPP

#include <vector>
#include "./vertex.hpp"
#include "./texture.hpp"

namespace gyoza
{

class Render_component
{
public:
    Render_component();

private:
    std::vector<Vertex> vertices{};
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    unsigned int vao{};
    unsigned int vbo{};
    unsigned int ebo{};

    void Buffor_data();
};

}

#endif
