#include <graphics/shader_library.hpp>

#include "engine.hpp"

void ShaderLibrary::add(const std::string &name, const std::string &vertex_path, const std::string &fragment_path) {
    shaders[name] = Engine::graphics_factory->create_shader(vertex_path, fragment_path);
}

std::shared_ptr<Shader> ShaderLibrary::get(const std::string &name) {
    if (const auto element = shaders.find(name); element != shaders.end()) {
        return element->second;
    }

    return nullptr;
}
