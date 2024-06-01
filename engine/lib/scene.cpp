#include "scene.hpp"
#include "object.hpp"

namespace Dog
{
    Scene::Scene()
    = default;

    Scene::~Scene()
    = default;

    void Scene::start()
    {
    }

    void Scene::update(const float deltaTime) const
    {
        for (const auto & component : components)
        {
            component->update(deltaTime);
        }
    }

    void Scene::instantiate(Component *component)
    {
        if (dynamic_cast<Camera *>(component))
        {
            mainCamera = dynamic_cast<Camera *>(component);
        }

        if (dynamic_cast<Object *>(component))
        {
            auto *object = dynamic_cast<Object *>(component);
            object->setCamera(mainCamera);
        }

        components.push_back(std::unique_ptr<Component>(component));
        component->start();
    }

    void Scene::destroy(const Component *component)
    {
        for (size_t i = 0; i < components.size(); i++)
        {
            if (components[i].get() == component)
            {
                components.erase(components.begin() + i);
                break;
            }
        }

        components.shrink_to_fit();
    }
}
