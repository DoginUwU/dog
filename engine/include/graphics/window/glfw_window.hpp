#pragma once
#include "window_api.hpp"
#include <GLFW/glfw3.h>

class GLFWWindow final : public WindowAPI {
public:
    void create_window(int width, int height, const std::string &title) override;

    void update() override;

    bool should_close() override;

    WindowProcAddress get_process_address(const char *name) override;

    ~GLFWWindow() override;

private:
    static void glfw_key_callback(GLFWwindow *window, int key, int scancode, int action, int mode);

    static void glfw_mouse_pos_callback(GLFWwindow *window, double x, double y);

    GLFWwindow *glfw_window = nullptr;
};
