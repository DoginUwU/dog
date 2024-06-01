#include "object.hpp"
#include "shaders.hpp"
#include "draw_queue.hpp"

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
        DrawQueue::instance->addTask([this] { _internalStart(); });
    }

    void Object::update(float deltaTime)
    {
        DrawQueue::instance->addTask([this, deltaTime] { _internalUpdate(deltaTime); });
    }

    void Object::_internalStart()
    {
        mesh.init();
    }

    void Object::_internalUpdate(float deltaTime)
    {
        if (sizeIsSet && !camera->frustum->aabbInFrustum(&aabb))
        {
            mesh.isActive = false;
            return;
        }

        mesh.isActive = true;
        mesh.draw();
    }

    void Object::setCamera(Camera *camera)
    {
        this->camera = camera;
    }

    void Object::setSize(const glm::vec3 min, const glm::vec3 max)
    {
        aabb.setMinMax(min, max);
        sizeIsSet = true;
    }
}
