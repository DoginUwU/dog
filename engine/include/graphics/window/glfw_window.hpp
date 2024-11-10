#pragma once
#include "window_api.hpp"
#include <GLFW/glfw3.h>

class GLFWWindow final : public WindowAPI {
public:
    void create_window(int width, int height, const std::string &title) override;

    void update() override;

    bool should_close() override;

    ~GLFWWindow() override;

private:
    GLFWwindow *glfw_window = nullptr;
};
