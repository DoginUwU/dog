#include "gl/shader.hpp"

#include <glad/gl.h>
#include <fstream>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

using namespace std;

namespace Dog
{
    Shader::Shader(const std::string vertexPath, const std::string fragmentPath)
    {
        uint vertexShader = loadShader(vertexPath, GL_VERTEX_SHADER);
        uint fragmentShader = loadShader(fragmentPath, GL_FRAGMENT_SHADER);

        program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        int success;
        char infoLog[512];
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(program, 512, NULL, infoLog);
            cout << "Shader linking failed: " << infoLog << endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        modelLoc = glGetUniformLocation(program, "model");
        viewLoc = glGetUniformLocation(program, "view");
        projectionLoc = glGetUniformLocation(program, "projection");
    }

    Shader::~Shader()
    {
        glDeleteProgram(program);
    }

    void Shader::use() const
    {
        glUseProgram(program);
    }

    void Shader::setMat4(uint loc, const glm::mat4 &mat) const
    {
        glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(mat));
    }

    void Shader::setVec3(uint loc, const glm::vec3 &vec) const
    {
        glUniform3fv(loc, 1, glm::value_ptr(vec));
    }

    uint Shader::loadShader(std::string path, uint type)
    {
        ifstream file(path);
        string source((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
        const char *sourcePtr = source.c_str();

        uint shader = glCreateShader(type);
        glShaderSource(shader, 1, &sourcePtr, NULL);
        glCompileShader(shader);

        int success;
        char infoLog[512];
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success)
        {
            glGetShaderInfoLog(shader, 512, NULL, infoLog);
            cout << "Shader compilation failed: " << infoLog << endl;
        }

        return shader;
    }
}
