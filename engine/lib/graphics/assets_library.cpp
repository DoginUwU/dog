#include <graphics/assets_library.hpp>

#include "engine.hpp"
#include "core/logger.hpp"

std::shared_ptr<Shader> AssetsLibrary::add_shader(const std::string &name, const std::string &vertex_path,
                                                  const std::string &fragment_path) {
    auto shader = Engine::graphics_factory->create_shader(vertex_path, fragment_path);
    shaders[name] = shader;

    return shader;
}

std::shared_ptr<Shader> AssetsLibrary::get_shader(const std::string &name) {
    if (const auto element = shaders.find(name); element != shaders.end()) {
        return element->second;
    }

    Logger::error("Failed to find shaders with name: %s", name.c_str());

    return nullptr;
}

void AssetsLibrary::add_material(const std::string &name, const Material &material) {
    materials[name] = std::make_shared<Material>(material);
}

std::shared_ptr<Material> AssetsLibrary::get_material(const std::string &name) {
    if (const auto element = materials.find(name); element != materials.end()) {
        return element->second;
    }

    Logger::error("Failed to find material with name: %s", name.c_str());

    return nullptr;
}
