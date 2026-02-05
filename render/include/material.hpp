#ifndef GYOZA_MATERIAL_TEXTURE_HPP
#define GYOZA_MATERIAL_TEXTURE_HPP

#include "./texture.hpp"

namespace gyoza
{

struct Material_texture
{
    Texture diffuse_texture{};
    Texture speculat_texture{};

    float shiness{};
};

}

#endif
