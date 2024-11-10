#pragma once
#include "window_api.hpp"

class GLFWWindow : public WindowAPI {
public:
    void create_window(int width, int height, const std::string &title) override;

    bool should_close() override;

private:
    long *glfw_window = nullptr;
};
