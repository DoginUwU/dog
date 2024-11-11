#include <graphics/opengl/opengl_api.hpp>
#include <glad/gl.h>

#include "core/logger.hpp"

void OpenGLAPI::init() {
    if (gladLoaderLoadGL() == 0) {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
}


void OpenGLAPI::clear() {
    glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLAPI::draw() {
}

uint OpenGLAPI::get_uniform_location(const uint program, const std::string &name) {
    return glGetUniformLocation(program, name.c_str());
}

uint OpenGLAPI::link_shaders(uint *shaders, const size_t size) {
    const auto program = glCreateProgram();

    for (size_t i = 0; i < size; i++) {
        glAttachShader(program, shaders[i]);
    }

    glLinkProgram(program);

    int success;
    glGetProgramiv(program, GL_LINK_STATUS, &success);
    if (success) {
        Logger::info("Shaders linked");
    } else {
        char infoLog[512];
        glGetShaderInfoLog(program, 512, nullptr, infoLog);
        Logger::error("Shader linking failed by: %s", infoLog);
    }

    for (size_t i = 0; i < size; i++) {
        glDeleteShader(shaders[i]);
    }

    return program;
}


uint OpenGLAPI::load_shader(const char *data, const ShaderType type) {
    auto opengl_type = GL_VERTEX_SHADER;

    if (type == ShaderType::FRAGMENT) {
        opengl_type = GL_FRAGMENT_SHADER;
    }

    const auto shader = glCreateShader(opengl_type);
    glShaderSource(shader, 1, &data, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success) {
        Logger::info("Shader loaded");
    } else {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        Logger::error("Shader compilation failed by: %s", infoLog);
    }

    return shader;
}

void OpenGLAPI::unlink_shaders(const uint program) {
    glDeleteProgram(program);
}


void OpenGLAPI::draw_mesh(std::unique_ptr<Mesh>) {
}


OpenGLAPI::~OpenGLAPI() = default;
