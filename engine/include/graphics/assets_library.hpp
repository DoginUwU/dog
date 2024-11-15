#pragma once
#include <memory>
#include <unordered_map>
#include <string>

#include "shader.hpp"
#include "core/material.hpp"

class AssetsLibrary {
public:
    std::shared_ptr<Shader> add_shader(const std::string &name, const std::string &vertex_path,
                                       const std::string &fragment_path);

    std::shared_ptr<Shader> get_shader(const std::string &name);

    std::shared_ptr<Material> add_material(const std::string &name, const Material &material);

    std::shared_ptr<Material> get_material(const std::string &name);

private:
    std::unordered_map<std::string, std::shared_ptr<Shader> > shaders;
    std::unordered_map<std::string, std::shared_ptr<Material> > materials;
};
