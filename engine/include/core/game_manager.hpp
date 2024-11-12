#pragma once
#include <memory>

#include "scene.hpp"
#include "graphics/shader_library.hpp"

class GameManager final {
public:
    GameManager();

    void set_active_scene(std::unique_ptr<Scene> scene);

    void update() const;

    inline static std::unique_ptr<ShaderLibrary> shader_library = nullptr;

private:
    std::unique_ptr<Scene> active_scene;
};
