#include "../include/render_manager.hpp"
#include <iostream>

using namespace gyoza;


void gyoza::Render_manager::Render()
{
    Process_input();

    glClearColor(0.1, 0.1, 0.7, 1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    auto& render_componets = resources.render_components;

    glm::mat4 view{1.0f};
    view = camera.Get_view_matrix();

    glm::mat4 model{1.0};
    model = glm::rotate(model, (float)glfwGetTime() * glm::radians(50.0f), glm::vec3(0.5f, 1.0f, 0.0f));

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

void gyoza::Render_manager::Process_input()
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
    {
        glfwSetWindowShouldClose(window, true);
    }

    if(glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
    {
        camera.Process_keyboard(Camera_movement::FORWARD, 0.03); ///@TODO Change to delta time.
    }
    if(glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
    {
        camera.Process_keyboard(Camera_movement::BACKWARD, 0.03); ///@TODO Change to delta time.
    }
    if(glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
    {
        camera.Process_keyboard(Camera_movement::LEFT, 0.03); ///@TODO Change to delta time.
    }
    if(glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
    {
        camera.Process_keyboard(Camera_movement::RIGHT, 0.03); ///@TODO Change to delta time.
    }
}

void gyoza::Render_manager::Frame_buffer_size_callback([[maybe_unused]] GLFWwindow* window, int width, int height)
{
    glViewport(0,0, width, height);
}
