#pragma once
#include <memory>

#include "scene.hpp"
#include "graphics/shader.hpp"

class LightManager final {
public:
    static void upload_lighting_data(const std::shared_ptr<Shader> &shader, const std::unique_ptr<Scene> &scene);
};
