#pragma once
#include <memory>

#include "mesh.hpp"
#include "renderer_api.hpp"
#include "shader.hpp"
#include "window/window_api.hpp"

class GraphicsFactory {
public:
    virtual std::unique_ptr<WindowAPI> create_window_api() = 0;

    virtual std::unique_ptr<RendererAPI> create_renderer_api() = 0;

    virtual std::shared_ptr<Shader> create_shader(const std::string &vertex_path, const std::string &fragment_path) = 0;

    virtual std::shared_ptr<Texture> create_texture(const std::string &path) = 0;

    virtual std::unique_ptr<Mesh> create_mesh() = 0;

    virtual ~GraphicsFactory() = default;
};
