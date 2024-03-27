#include "gl/window.hpp"
#include "gl/input.hpp"

#include <glad/gl.h>
#include <stdexcept>

namespace Dog
{
    Window::Window()
    {
        window = glfwCreateWindow(800, 600, "Engine", nullptr, nullptr);

        if (!window)
        {
            throw std::runtime_error("Failed to create window");
        }

        glfwMakeContextCurrent(window);

        if (gladLoadGL(glfwGetProcAddress) == 0)
        {
            throw std::runtime_error("Failed to initialize GLAD");
        }

        glViewport(0, 0, 800, 600);

        // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        glEnable(GL_DEPTH_TEST);

        Input::init(window);
    }

    Window::~Window()
    {
        glfwDestroyWindow(window);
    }

    void Window::update() const
    {
        glfwSwapBuffers(window);

        if (Input::isKeyPressed(GLFW_KEY_ESCAPE))
        {
            close();
        }
    }

    void Window::close() const
    {
        glfwSetWindowShouldClose(window, true);
    }

    bool Window::shouldClose() const
    {
        return glfwWindowShouldClose(window);
    }
}
