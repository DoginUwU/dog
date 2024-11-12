#pragma once
#include "graphics/shader.hpp"

class OpenGLShader final : public Shader {
public:
    OpenGLShader(const std::string &vertex_source, const std::string &fragment_source);

    void bind() override;

    void unbind() override;

    ~OpenGLShader() override;

private:
    unsigned int program;
    unsigned int location_model;
    unsigned int location_view;
    unsigned int location_projection;

    static unsigned int load_shader(const char *, ShaderType type);

    static unsigned int get_uniform_location(uint program, const std::string &name);

    static unsigned int link_shaders(const uint *shaders, size_t size);
};
