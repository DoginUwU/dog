#include <stdexcept>
#include <graphics/window/glfw_window.hpp>

void GLFWWindow::create_window(const int width, const int height, const std::string &title) {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (!glfwInit()) {
        throw std::runtime_error("Failed to initialize GLFW");
    }

    glfw_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

    if (glfw_window == nullptr) {
        throw std::runtime_error("Failed to create new GLFW window");
    }

    glfwMakeContextCurrent(glfw_window);
    glfwSwapInterval(1);
}

void GLFWWindow::update() {
    glfwSwapBuffers(glfw_window);
    glfwPollEvents();
}

bool GLFWWindow::should_close() {
    return glfwWindowShouldClose(glfw_window);
}

GLFWWindow::~GLFWWindow() {
    glfwDestroyWindow(glfw_window);
    glfwTerminate();
}
