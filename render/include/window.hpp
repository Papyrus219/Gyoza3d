#ifndef GYOZA_WINDOW_HPP
#define GYOZA_WINDOW_HPP

#include <string>
#include "./setup.hpp"

namespace gyoza
{

class Window
{
public:
    Window();
    Window(std::string title_, unsigned int width_, unsigned int height_);

    void Create(std::string title, unsigned int width, unsigned int height);
    void Close() {glfwSetWindowShouldClose(window, true);};

    void Clear();
    void Display();

    bool Get_is_open() {return !glfwWindowShouldClose(window);};
    std::string Get_title() {return title;};
    unsigned int Get_width() {return width;};
    unsigned int Get_height() {return height;};

private:
    GLFWwindow* window{};

    std::string title{};
    unsigned int width{};
    unsigned int height{};
};

}

#endif // GYOZA_WINDOW_HPP
