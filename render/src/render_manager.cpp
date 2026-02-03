#include "render_manager.hpp"
#include <iostream>

using namespace gyoza;

gyoza::Render_manager::Render_manager(Resource_manager& resources_, int window_height, int window_width): resources{resources_}, WINDOW_HEIGHT{window_height}, WINDOW_WIDTH{window_width}
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Gyoza 3D", NULL, NULL);
    if(!window)
    {
        std::cerr << "Failed to create glfw window.\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);

    if(!gladLoadGLLoader( (GLADloadproc)glfwGetProcAddress ))
    {
        std::cerr << "Failed to initialize glad.\n";
        glfwTerminate();
        std::exit(EXIT_FAILURE);
    }

    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glfwSetFramebufferSizeCallback(window, Frame_buffer_size_callback);

    glEnable(GL_DEPTH_TEST);

    light_shader.emplace("../../render/shaders/light_shader.vs", "../../render/shaders/light_shader.fs");
}

void gyoza::Render_manager::Render()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto& render_componets = resources.render_components;

    glm::mat4 view{1.0f};
    view = glm::translate(view, glm::vec3(0.0, 0.0, -3.0f));

    glm::mat4 model{1.0};
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f),
                        glm::vec3(0.5f, 1.0f, 0.0f));

    glm::mat4 projection{};
    projection = glm::perspective(glm::radians(45.0f), static_cast<float>(WINDOW_WIDTH)/WINDOW_HEIGHT, 0.1f, 100.0f);

    for(auto& render_component: render_componets)
    {
        light_shader->Use();
        light_shader->Set_matrix4("model", model);
        light_shader->Set_matrix4("view", view);
        light_shader->Set_matrix4("projection", projection);

        render_component->Draw(*light_shader);
    }

    glfwSwapBuffers(window);
    glfwPollEvents();
}


void gyoza::Render_manager::Frame_buffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}
