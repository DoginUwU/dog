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

std::shared_ptr<Material> AssetsLibrary::add_material(const std::string &name, const Material &material) {
    auto shared_material = std::make_shared<Material>(material);
    materials[name] = shared_material;

    return shared_material;
}

std::shared_ptr<Material> AssetsLibrary::get_material(const std::string &name) {
    if (const auto element = materials.find(name); element != materials.end()) {
        return element->second;
    }

    Logger::error("Failed to find material with name: %s", name.c_str());

    return nullptr;
}

std::shared_ptr<Texture> AssetsLibrary::add_texture(const std::string &name, const std::string &path) {
    auto texture = Engine::graphics_factory->create_texture(path);
    textures[name] = texture;

    return texture;
}

std::shared_ptr<Texture> AssetsLibrary::get_texture(const std::string &name) {
    if (const auto element = textures.find(name); element != textures.end()) {
        return element->second;
    }

    Logger::error("Failed to find texture with name: %s", name.c_str());

    return nullptr;
}
