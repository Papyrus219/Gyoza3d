#include "./texture.hpp"
#include "./lib/stb_image.h"
#include <glad/glad.h>
#include <iostream>

gyoza::Texture::Texture(std::filesystem::path path, std::string type)
{
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* data{};
    int width{}, height{}, nr_chanels{};
    GLenum format{};

    data = stbi_load(path.c_str(), &width, &height, &nr_chanels, 0);
    if(data)
    {
        switch(nr_chanels)
        {
            case 1:
                format = GL_RED;
                break;
            case 3:
                format = GL_RGB;
                break;
            case 4:
                format = GL_RGBA;
                break;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        this->type = type;
    }
    else
    {
        std::cerr << "Failed to load texuture.\n";
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}

void gyoza::Texture::Load_from_file(std::filesystem::path path, std::string type)
{
    glGenTextures(1, &this->id);
    glBindTexture(GL_TEXTURE_2D, this->id);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    unsigned char* data{};
    int width{}, height{}, nr_chanels{};
    GLenum format{};

    data = stbi_load(path.c_str(), &width, &height, &nr_chanels, 0);
    if(data)
    {
        switch(nr_chanels)
        {
            case 1:
                format = GL_RED;
                break;
            case 3:
                format = GL_RGB;
                break;
            case 4:
                format = GL_RGBA;
                break;
        }

        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
        this->type = type;
    }
    else
    {
        std::cerr << "Failed to load texuture.\n";
    }
    stbi_image_free(data);

    glBindTexture(GL_TEXTURE_2D, 0);
}
