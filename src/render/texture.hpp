#ifndef GYOZA_TEXTURE_HPP
#define GYOZA_TEXTURE_HPP

#include <filesystem>

namespace gyoza
{

struct Texture
{
public:
    Texture() = default;
    Texture(std::filesystem::path path, std::string type = "diffuse");

    void Load_from_file(std::filesystem::path path, std::string type = "diffuse");

private:
    unsigned int id{};
    std::string type{"diffuse"};
};

}

#endif
