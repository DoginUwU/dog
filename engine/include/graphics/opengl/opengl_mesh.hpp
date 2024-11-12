#pragma once
#include <cstdint>

#include "graphics/mesh.hpp"

class OpenGLMesh final : public Mesh {
public:
    OpenGLMesh();

    void update() override;

    void bind() override;

    void draw() override;

    void unbind() override;

    ~OpenGLMesh() override;

private:
    bool updated_first_time = false;

    uint32_t vao{};
    uint32_t vbo{};
    uint32_t ebo{};
};
