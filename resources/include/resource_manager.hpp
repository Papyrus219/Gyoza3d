#ifndef GYOZA_RESOURCE_MANAGER_HPP
#define GYOZA_RESOURCE_MANAGER_HPP

#include <vector>
#include <memory>
#include "../../data/data_component.hpp"
#include "../../physic/src/physic_component.hpp"

namespace gyoza
{

class Resource_manager
{
public:
    std::vector<Data_component> data_components{};
    std::vector<Physic_component> physics_components{};
};

}

#endif // GYOZA_RESOURCE_MANAGER_HPP
