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
        DrawQueue::instance->addTask(std::bind(&Object::_internalStart, this));
    }

    void Object::update(float deltaTime)
    {
        DrawQueue::instance->addTask(std::bind(&Object::_internalUpdate, this, deltaTime));
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

    void Object::setSize(glm::vec3 min, glm::vec3 max)
    {
        aabb.setMinMax(min, max);
        sizeIsSet = true;
    }
}
