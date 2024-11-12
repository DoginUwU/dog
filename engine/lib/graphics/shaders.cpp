#include <graphics/shaders.hpp>

void Shaders::start() {
    object_shader = std::make_unique<Shader>(OBJECT_VERTEX_SHADER, OBJECT_FRAGMENT_SHADER);
}

void Shaders::clean() {
}
