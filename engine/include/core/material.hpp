#pragma once
#include <memory>

#include "graphics/shader.hpp"
#include "graphics/texture.hpp"

struct Material {
    Vector3F ambient{};
    Vector3F diffuse{};
    Vector3F specular{};
    float shininess;

    std::shared_ptr<Shader> shader = nullptr;
    std::shared_ptr<Texture> texture = nullptr;
};
