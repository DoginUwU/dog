#pragma once
#include <memory>

#include "graphics/shader.hpp"
#include "graphics/texture.hpp"

struct Material {
    std::shared_ptr<Shader> shader = nullptr;
    std::shared_ptr<Texture> texture = nullptr;
};
