#ifndef GYOZA_RENDER_COMPONENT_HPP
#define GYOZA_RENDER_COMPONENT_HPP

#include <vector>
#include "./vertex.hpp"
#include "./texture.hpp"
#include "./lib/shader.hpp"

namespace gyoza
{

class Render_component
{
public:
    void Draw(Shader &shader);

    virtual ~Render_component() = default;
protected:
    Render_component(unsigned int data_id_);

    std::vector<Vertex> vertices{};
    std::vector<unsigned int> indices;
    std::vector<Texture> textures;

    unsigned int vao{};
    unsigned int vbo{};
    unsigned int ebo{};

    unsigned int data_id{};

    void Buffor_data();
};

}

#endif
