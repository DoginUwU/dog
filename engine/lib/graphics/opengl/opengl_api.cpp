#include <graphics/opengl/opengl_api.hpp>
#include <GL/gl.h>

void OpenGLAPI::init() {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}


void OpenGLAPI::clear() {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLAPI::draw() {
}

OpenGLAPI::~OpenGLAPI() = default;
