#pragma once
#include <memory>
#include <unordered_map>
#include <string>

#include "shader.hpp"

class ShaderLibrary {
public:
    void add(const std::string &name, const std::string &vertex_path, const std::string &fragment_path);

    std::shared_ptr<Shader> get(const std::string &name);

private:
    std::unordered_map<std::string, std::shared_ptr<Shader> > shaders;
};
