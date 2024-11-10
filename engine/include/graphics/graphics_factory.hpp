#pragma once
#include <memory>

#include "renderer_api.hpp"
#include "window/window_api.hpp"

class GraphicsFactory {
public:
    virtual std::unique_ptr<WindowAPI> create_window_api() = 0;

    virtual std::unique_ptr<RendererAPI> create_renderer_api() = 0;

    virtual ~GraphicsFactory() {
    };
};