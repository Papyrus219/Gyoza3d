#ifndef GYOZA_RENDER_MANAGER_HPP
#define GYOZA_RENDER_MANAGER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <optional>
#include "../../resources/src/resource_manager.hpp"

namespace gyoza {

/**
 * @todo write docs
 */
class Render_manager
{
public:
    Render_manager(Resource_manager& resources_, int window_height, int window_width);

    bool Is_open() {return !glfwWindowShouldClose(window);};

    void Render();
private:

    static void Frame_buffer_size_callback(GLFWwindow* window, int width, int height);

    GLFWwindow* window{};

    Resource_manager& resources;

    const int WINDOW_HEIGHT{};
    const int WINDOW_WIDTH{};

    std::optional<Shader> light_shader{};
};

}

#endif // GYOZA_RENDER_MANAGER_HPP
