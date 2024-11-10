#include <stdexcept>
#include <graphics/window/glfw_window.hpp>

void GLFWWindow::create_window(const int width, const int height, const std::string &title) {
    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    glfwMakeContextCurrent(glfw_window);
    glfwSwapInterval(1);
}

void GLFWWindow::update() {
    glfwSwapBuffers(glfw_window);
}

bool GLFWWindow::should_close() {
    return glfwWindowShouldClose(glfw_window);
}

GLFWWindow::~GLFWWindow() {
    glfwDestroyWindow(glfw_window);
}
