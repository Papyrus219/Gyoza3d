#ifndef GYOZA_VERTEX_HPP
#define GYOZA_VERTEX_HPP

#include <glm/glm.hpp>

namespace gyoza
{

struct Vertex
{
    glm::vec3 possition{};
    glm::vec3 normal{};
    glm::vec2 tex_cords{};
};

}

#endif
