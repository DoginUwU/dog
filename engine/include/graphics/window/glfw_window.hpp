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
    static void glfw_key_callback(GLFWwindow *window, const int key, int scancode, const int action, int mode);

    GLFWwindow *glfw_window = nullptr;
};
