#include "shaders.hpp"

namespace Dog
{
    void Shaders::init()
    {
        objectShader = new Shader(OBJECT_VERTEX_SHADER, OBJECT_FRAGMENT_SHADER);
    }

    void Shaders::cleanup()
    {
        delete objectShader;
    }
}
