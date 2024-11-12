#pragma once

#include <string>

enum class ShaderType {
    VERTEX,
    FRAGMENT
};

class Shader {
public:
    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual ~Shader() = default;

private:
    static uint load_shader(const std::string &path, ShaderType type);
};
