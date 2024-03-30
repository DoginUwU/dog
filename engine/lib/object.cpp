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
        Shaders::objectShader->setMat4(Shaders::objectShader->modelLoc, transform.matrix);

        if (sizeIsSet && !camera->frustum->aabbInFrustum(&aabb))
        {
            return;
        }

        mesh.draw();
    }

    void Object::setCamera(Camera *camera)
    {
        this->camera = camera;
    }

    void Object::setSize(glm::vec3 min, glm::vec3 max)
    {
        aabb.setMinMax(min, max);
        sizeIsSet = true;
    }
}
