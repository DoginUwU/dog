#include "object.hpp"
#include "shaders.hpp"

namespace Dog
{
    Object::Object()
    {
    }

    Object::~Object()
    {
    }

    void Object::update(float deltaTime)
    {
        mesh.draw();
        Shaders::objectShader->setMat4(Shaders::objectShader->modelLoc, transform.matrix);
    }
}
