#include "object.hpp"
#include "shaders.hpp"

namespace Dog
{
    Object::Object()
    {
    }

    Object::~Object()
    {
        mesh.clear();
    }

    void Object::update(float deltaTime)
    {
        mesh.draw();
        Shaders::objectShader->setMat4(Shaders::objectShader->modelLoc, transform.matrix);
    }
}
