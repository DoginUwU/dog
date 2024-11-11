#pragma once

#include <string>

enum class ShaderType {
    VERTEX,
    FRAGMENT
};

class Shader {
public:
    unsigned int program;
    unsigned int location_model;
    unsigned int location_view;
    unsigned int location_projection;

    Shader(const std::string &vertex_path, const std::string &fragment_path);

    ~Shader();

private:
    static uint load_shader(const std::string &path, ShaderType type);
};
