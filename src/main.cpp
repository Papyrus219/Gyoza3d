#include <iostream>

#include "../render/src/render_manager.hpp"
#include "../resources/src/resource_manager.hpp"

int main()
{
    gyoza::Resource_manager resource{};

    gyoza::Render_manager rendere{resource, 800, 500};
    resource.render_components.push_back( std::make_unique<gyoza::Sphere_render_component>(2.0f, 50, 50, 2) );

    while(rendere.Is_open())
    {
        rendere.Render();
    }

    return 0;
}
