#include "../include/window.hpp"
#include <stdexcept>

using namespace gyoza;

gyoza::Window::Window()
{
    window = glfwCreateWindow(width, height, title.c_str(), 0, 0);
    if(!window)
    {
        throw std::runtime_error{"Failed to create window."};
    }
    glfwMakeContextCurrent(window);
}

gyoza::Window::Window(std::string title_, unsigned int width_, unsigned int height_): title{title_}, width{width_}, height{height_}
{

}

void gyoza::Window::Create(std::string title, unsigned int width, unsigned int height)
{
    this->title = title;
    this->width = width;
    this->height = height;
}

void gyoza::Window::Clear()
{
    glClearColor(0.0, 0.0, 1.0, 1.0);
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
}

void gyoza::Window::Display()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}
