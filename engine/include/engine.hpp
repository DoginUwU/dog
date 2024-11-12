#pragma once

#include <memory>

#include "core/game_manager.hpp"
#include "graphics/graphics_factory.hpp"
#include "graphics/renderer_api.hpp"
#include "graphics/shader_library.hpp"
#include "graphics/window/window_api.hpp"

class Engine {
public:
    Engine();

    void loop() const;

    inline static std::unique_ptr<ShaderLibrary> shader_library = nullptr;
    inline static std::unique_ptr<GameManager> game_manager = nullptr;
    inline static std::unique_ptr<GraphicsFactory> factory = nullptr;
    inline static std::unique_ptr<RendererAPI> renderer = nullptr;
    inline static std::unique_ptr<WindowAPI> window = nullptr;
};
