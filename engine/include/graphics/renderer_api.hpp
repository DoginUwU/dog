#pragma once
#include <memory>

#include "mesh.hpp"
#include "shader.hpp"

class RendererAPI {
public:
    virtual void init() = 0;

    virtual void clear() = 0;

    virtual void draw() = 0;

    virtual void draw_mesh(std::unique_ptr<Mesh>) = 0;

    virtual uint get_uniform_location(uint program, const std::string &name) = 0;

    virtual uint link_shaders(uint *shaders, size_t size) = 0;

    virtual uint load_shader(const char *data, ShaderType type) = 0;

    virtual void unlink_shaders(uint program) = 0;

    virtual ~RendererAPI() = default;
};
