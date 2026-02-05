#ifndef GYOZA_SETUP_HPP
#define GYOZA_SETUP_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace gyoza
{

struct Setup
{
    Setup()
    {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if(!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ))
        {
            std::cerr << "Failed to initialize glad.\n";
            std::exit(EXIT_FAILURE);
        }
    }

    ~Setup()
    {
        glfwTerminate();
    }
} setup{};

}

#endif
