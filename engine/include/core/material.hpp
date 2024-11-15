#pragma once
#include <memory>

#include "graphics/shader.hpp"

struct Material {
    std::shared_ptr<Shader> shader = nullptr;
};
