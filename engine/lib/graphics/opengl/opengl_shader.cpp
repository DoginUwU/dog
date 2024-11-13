#include <graphics/opengl/opengl_shader.hpp>

#include "core/logger.hpp"

OpenGLShader::OpenGLShader(const std::string &vertex_source, const std::string &fragment_source) {
    const auto vertex_shader = load_shader(vertex_source.c_str(), ShaderType::VERTEX);
    const auto fragment_shader = load_shader(fragment_source.c_str(), ShaderType::FRAGMENT);

    const uint32_t shaders[] = {vertex_shader, fragment_shader};
    program = link_shaders(shaders, std::size(shaders));
}

void OpenGLShader::bind() {
    glUseProgram(program);
}

void OpenGLShader::unbind() {
    glUseProgram(0);
}

void OpenGLShader::set_uniform(const std::string &name, const Matrix4F &value) {
    auto uniform_location = get_uniform_location(name);

    if (uniform_location == GL_FALSE) {
        uniform_location = glGetUniformLocation(program, name.c_str());
    }

    glUniformMatrix4fv(uniform_location, 1, GL_TRUE, value.elements.data());
}

GLint OpenGLShader::get_uniform_location(const std::string &name) {
    if (const auto element = uniforms.find(name); element != uniforms.end()) {
        return element->second;
    }

    return GL_FALSE;
}

unsigned int OpenGLShader::link_shaders(const uint *shaders, const size_t size) {
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
        glGetProgramInfoLog(program, 512, nullptr, infoLog);
        Logger::error("Shader linking failed by: %s", infoLog);
    }

    for (size_t i = 0; i < size; i++) {
        glDeleteShader(shaders[i]);
    }

    return program;
}

unsigned int OpenGLShader::load_shader(const char *data, const ShaderType type) {
    auto shader_type = GL_VERTEX_SHADER;

    if (type == ShaderType::FRAGMENT) {
        shader_type = GL_FRAGMENT_SHADER;
    }

    const auto shader = glCreateShader(shader_type);
    glShaderSource(shader, 1, &data, nullptr);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (success) {
        Logger::info("Shader compiled");
    } else {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, nullptr, infoLog);
        Logger::error("Shader compilation failed by: %s", infoLog);
    }

    return shader;
}

OpenGLShader::~OpenGLShader() {
    glDeleteProgram(program);
}
