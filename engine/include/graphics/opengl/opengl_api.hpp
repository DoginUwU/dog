#pragma once
#include "graphics/renderer_api.hpp"

class OpenGLAPI final : public RendererAPI {
public:
    void init() override;

    void clear() override;

    void draw() override;

    uint get_uniform_location(uint program, const std::string &name) override;

    uint link_shaders(uint *shaders, size_t size) override;

    uint load_shader(const char *data, ShaderType type) override;

    void unlink_shaders(uint program) override;

    void draw_mesh(std::unique_ptr<Mesh>) override;

    ~OpenGLAPI() override;
};
