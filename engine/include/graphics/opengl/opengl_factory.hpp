#pragma once
#include "opengl_api.hpp"
#include "graphics/graphics_factory.hpp"
#include "graphics/window/glfw_window.hpp"

class OpenGLFactory final : public GraphicsFactory {
public:
    std::unique_ptr<WindowAPI> create_window_api() override {
        return std::make_unique<GLFWWindow>();
    }

    std::unique_ptr<RendererAPI> create_renderer_api() override {
        return std::make_unique<OpenGLAPI>();
    }

    ~OpenGLFactory() override {
    };
};
