#pragma once
#include <unordered_map>

#include "glad/gl.h"
#include "graphics/shader.hpp"

class OpenGLShader final : public Shader {
public:
    OpenGLShader(const std::string &vertex_source, const std::string &fragment_source);

    void bind() override;

    void unbind() override;

    void set_uniform(const std::string &name, const Matrix4F &value) override;

    void set_uniform(const std::string &name, const Vector3F &value) override;

    void set_uniform(const std::string &name, float value) override;

    void set_uniform(const std::string &name, bool value) override;

    ~OpenGLShader() override;

private:
    unsigned int program;
    std::unordered_map<std::string, GLint> uniforms;

    unsigned int load_shader(const char *, ShaderType type);

    static unsigned int link_shaders(const uint *shaders, size_t size);

    GLint get_uniform_location(const std::string &name);
};
