#pragma once

#include "file/image_reader.hpp"
#include "graphics/texture.hpp"

class OpenGLTexture final : public Texture {
public:
    explicit OpenGLTexture(const std::string &path);

    void bind() override;

    void unbind() override;

    ~OpenGLTexture() override = default;

private:
    unsigned int texture;
};
