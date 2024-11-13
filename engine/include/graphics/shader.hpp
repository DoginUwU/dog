#pragma once

#include <string>

#include "math/matrix_4f.hpp"

enum class ShaderType {
    VERTEX,
    FRAGMENT
};

class Shader {
public:
    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual void set_uniform(const std::string &name, const Matrix4F &value) = 0;

    virtual ~Shader() = default;

private:
    static uint load_shader(const std::string &path, ShaderType type);
};
