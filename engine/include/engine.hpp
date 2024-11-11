#pragma once

#include <memory>

#include "core/game_manager.hpp"
#include "graphics/renderer_api.hpp"
#include "graphics/window/window_api.hpp"

class Engine {
public:
    Engine();

    void loop() const;

    std::unique_ptr<GameManager> game_manager;

private:
    std::unique_ptr<WindowAPI> window;
    std::unique_ptr<RendererAPI> renderer;
};
