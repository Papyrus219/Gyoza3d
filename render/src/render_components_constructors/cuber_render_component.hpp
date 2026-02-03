#ifndef GYOZA_CUBER_RENDER_COMPONENT_HPP
#define GYOZA_CUBER_RENDER_COMPONENT_HPP

#include "../render_component.hpp"

namespace gyoza
{

class Cuber_render_component : public Render_component
{
public:
    Cuber_render_component(unsigned int data_id_);

    ~Cuber_render_component() = default;
};

}

#endif // GYOZA_CUBER_RENDER_COMPONENT_HPP
