#ifndef GYOZA_RENDER_MANAGER_HPP
#define GYOZA_RENDER_MANAGER_HPP

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <optional>
#include "./lib/fly_camera.hpp"
#include "./lib/shader.hpp"

namespace gyoza {

/**
 * @todo write docs
 */
class Render_manager
{
public:
    bool Is_open() {return !glfwWindowShouldClose(window);};

    void Render();
private:
    void Process_input();

    static void Frame_buffer_size_callback(GLFWwindow* window, int width, int height);

    GLFWwindow* window{};

    Fly_camera camera{};
    Resource_manager& resources;

    const int WINDOW_WIDTH{};
    const int WINDOW_HEIGHT{};

    std::optional<Shader> light_shader{};
};

}

#endif // GYOZA_RENDER_MANAGER_HPP
