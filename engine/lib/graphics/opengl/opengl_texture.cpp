#include "graphics/opengl/opengl_texture.hpp"
#include <glad/gl.h>

OpenGLTexture::OpenGLTexture(const std::string &path) {
    texture = 0;
    const auto image = ImageReader::read(path);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);

    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTextureParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image.width, image.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image.data);
    glGenerateMipmap(GL_TEXTURE_2D);

    ImageReader::free(image);
}

void OpenGLTexture::bind() {
    // TODO: Handle texture id dynamic
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture);
}

void OpenGLTexture::unbind() {
    glBindTexture(GL_TEXTURE_2D, 0);
}
