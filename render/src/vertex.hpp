#ifndef GYOZA_VERTEX_HPP
#define GYOZA_VERTEX_HPP

#include <glm/glm.hpp>

namespace gyoza
{

struct Vertex
{
    Vertex(float poss_x, float poss_y, float poss_z, float normal_x, float normal_y, float normal_z, float tex_cords_x, float tex_cords_y);

    glm::vec3 possition{};
    glm::vec3 normal{};
    glm::vec2 tex_cords{};
};

}

#endif
