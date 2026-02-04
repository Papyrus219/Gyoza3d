#ifndef GYOZA_SPHERE_RENDER_COMPONENT_HPP
#define GYOZA_SPHERE_RENDER_COMPONENT_HPP

#include "../render_component.hpp"

namespace gyoza
{

class Sphere_render_component : public Render_component
{
public:
    Sphere_render_component(float radius, unsigned int stack_amount, unsigned int sector_count, unsigned int data_id);

    virtual ~Sphere_render_component() = default;
};

}

#endif // GYOZA_SPHERE_RENDER_COMPONENT_HPP
