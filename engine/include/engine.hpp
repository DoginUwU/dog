#pragma once

#include <memory>

#include "graphics/renderer_api.hpp"
#include "graphics/window/window_api.hpp"

class Engine {
public:
    Engine();

    void loop() const;

private:
    std::unique_ptr<WindowAPI> window;
    std::unique_ptr<RendererAPI> renderer;
};
