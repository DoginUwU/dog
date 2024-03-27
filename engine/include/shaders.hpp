#ifndef SHADERS_HPP
#define SHADERS_HPP
#include "gl/shader.hpp"
#include <string>

namespace Dog
{
    class Shaders
    {
    public:
        inline static Shader *objectShader = nullptr;

        static void init();
        static void cleanup();

    private:
        inline static const std::string OBJECT_VERTEX_SHADER = "shaders/object.vert";
        inline static const std::string OBJECT_FRAGMENT_SHADER = "shaders/object.frag";
    };
}
#endif
