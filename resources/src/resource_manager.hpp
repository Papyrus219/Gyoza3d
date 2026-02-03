#ifndef GYOZA_RESOURCE_MANAGER_HPP
#define GYOZA_RESOURCE_MANAGER_HPP

#include <vector>
#include "../../data/data_component.hpp"
#include "../../physic/src/physic_component.hpp"
#include "../../render/src/render_component.hpp"

namespace gyoza
{

class Resource_manager
{
    std::vector<Data_component> data_components{};
    std::vector<Physic_component> physics_components{};
    std::vector<Render_component> render_components{};
};

}

#endif // GYOZA_RESOURCE_MANAGER_HPP
