#pragma once

#include <memory>

#include "core/game_manager.hpp"
#include "graphics/graphics_factory.hpp"
#include "graphics/renderer_api.hpp"
#include "graphics/window/window_api.hpp"

class Engine {
public:
    Engine();

    static void loop();

    inline static std::unique_ptr<GameManager> game_manager = nullptr;
    inline static std::unique_ptr<GraphicsFactory> graphics_factory = nullptr;
    inline static std::unique_ptr<RendererAPI> renderer = nullptr;
    inline static std::unique_ptr<WindowAPI> window = nullptr;
};
