#pragma once
#include <memory>

#include "scene.hpp"
#include "time.hpp"
#include "graphics/shader_library.hpp"

class GameManager final {
public:
    GameManager();

    static void set_active_scene(std::unique_ptr<Scene> scene);

    static void update();

    inline static std::unique_ptr<ShaderLibrary> shader_library = nullptr;
    inline static std::unique_ptr<Scene> active_scene = nullptr;
    inline static std::unique_ptr<Time> time = nullptr;
};
