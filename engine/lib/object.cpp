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
        mesh.active = camera->frustum->aabbInFrustum(&aabb);

        mesh.draw();
        Shaders::objectShader->setMat4(Shaders::objectShader->modelLoc, transform.matrix);
    }

    void Object::setCamera(Camera *camera)
    {
        this->camera = camera;
    }

    void Object::setFrustumMixMax(glm::vec3 min, glm::vec3 max)
    {
        aabb.setMinMax(min, max);
    }
}
