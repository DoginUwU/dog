#pragma once
#include "opengl_api.hpp"
#include "opengl_mesh.hpp"
#include "opengl_shader.hpp"
#include "opengl_texture.hpp"
#include "file/file_reader.hpp"
#include "graphics/graphics_factory.hpp"
#include "graphics/window/glfw_window.hpp"

class OpenGLFactory final : public GraphicsFactory {
public:
    std::unique_ptr<WindowAPI> create_window_api() override {
        return std::make_unique<GLFWWindow>();
    }

    std::unique_ptr<RendererAPI> create_renderer_api() override {
        return std::make_unique<OpenGLAPI>();
    }

    std::shared_ptr<Shader> create_shader(const std::string &vertex_path, const std::string &fragment_path) override {
        const auto vertex_source = FileReader::read(vertex_path);
        const auto fragment_source = FileReader::read(fragment_path);

        return std::make_shared<OpenGLShader>(vertex_source, fragment_source);
    }

    std::unique_ptr<Mesh> create_mesh() override {
        return std::make_unique<OpenGLMesh>();
    }

    std::shared_ptr<Texture> create_texture(const std::string &path) override {
        return std::make_unique<OpenGLTexture>(path);
    }

    ~OpenGLFactory() override = default;
};
