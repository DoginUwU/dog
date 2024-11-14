#include <stdexcept>
#include <graphics/window/glfw_window.hpp>

#include "core/input.hpp"

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

    glfwSetKeyCallback(glfw_window, glfw_key_callback);
    glfwSetCursorPosCallback(glfw_window, glfw_mouse_pos_callback);

    glfwSetInputMode(glfw_window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
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

WindowProcAddress GLFWWindow::get_process_address(const char *name) {
    return glfwGetProcAddress(name);
}

void GLFWWindow::glfw_key_callback(GLFWwindow *window, const int key, int scancode, const int action, int mode) {
    auto state = KeyState::Released;

    if (action != GLFW_RELEASE) {
        state = KeyState::Pressed;
    }

    Input::key_callback(key, state);
}

void GLFWWindow::glfw_mouse_pos_callback(GLFWwindow *window, const double x, const double y) {
    Input::mouse_pos_callback(static_cast<float>(x), static_cast<float>(y));
}
