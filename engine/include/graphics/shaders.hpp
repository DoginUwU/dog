#pragma once
#include <memory>
#include <string>

#include "shader.hpp"

class Shaders {
public:
    inline static std::unique_ptr<Shader> object_shader;

    static void start();

    static void clean();

private:
    inline static const std::string OBJECT_VERTEX_SHADER = "resources/shaders/object.vert";
    inline static const std::string OBJECT_FRAGMENT_SHADER = "resources/shaders/object.frag";
};
