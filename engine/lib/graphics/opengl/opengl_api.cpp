#include <stdexcept>
#include <graphics/opengl/opengl_api.hpp>
#include <glad/gl.h>

OpenGLAPI::OpenGLAPI() = default;


void OpenGLAPI::init() {
    if (gladLoaderLoadGL() == 0) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glEnable(GL_CULL_FACE);
}


void OpenGLAPI::clear() {
    glClearColor(0.5f, 0.95f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLAPI::draw() {
}

void OpenGLAPI::toggle_wireframe_mode() {
    wireframe = !wireframe;

    if (wireframe) {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }
}

OpenGLAPI::~OpenGLAPI() = default;
