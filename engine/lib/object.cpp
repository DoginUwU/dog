#include "object.hpp"
#include "shaders.hpp"
#include "gl/mesh_queue.hpp"

namespace Dog
{
    Object::Object()
    {
        mesh.transform = &transform;
    }

    Object::~Object()
    {
        // mesh.clear();
    }

    void Object::start()
    {
        MeshQueue::instance->addMeshToQueue(&mesh);
    }

    void Object::update(float deltaTime)
    {
        if (sizeIsSet && !camera->frustum->aabbInFrustum(&aabb))
        {
            mesh.isActive = false;
            return;
        }

        mesh.isActive = true;
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
