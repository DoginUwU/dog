#include <fstream>
#include <graphics/shader.hpp>

#include "engine.hpp"
#include "core/logger.hpp"

Shader::Shader(const std::string &vertex_path, const std::string &fragment_path) {
    const auto vertex_shader = load_shader(vertex_path, ShaderType::VERTEX);
    const auto fragment_shader = load_shader(fragment_path, ShaderType::FRAGMENT);

    uint32_t shaders[] = {vertex_shader, fragment_shader};
    program = Engine::renderer->link_shaders(shaders, std::size(shaders));

    location_view = Engine::renderer->get_uniform_location(program, "view");
    location_model = Engine::renderer->get_uniform_location(program, "model");
    location_projection = Engine::renderer->get_uniform_location(program, "projection");
}

Shader::~Shader() {
    Engine::renderer->unlink_shaders(program);
}

uint Shader::load_shader(const std::string &path, const ShaderType type) {
    std::ifstream file(path.c_str());

    if (file.fail()) {
        Logger::error("Failed to open file with path: %s", path.c_str());
    }

    const std::string source((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    const char *data = source.c_str();

    file.close();

    return Engine::renderer->load_shader(data, type);
}
