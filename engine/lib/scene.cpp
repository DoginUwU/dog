#include "scene.hpp"

namespace Dog
{
    Scene::Scene()
    {
    }

    Scene::~Scene()
    {
    }

    void Scene::start()
    {
    }

    void Scene::update(float deltaTime)
    {
        for (size_t i = 0; i < components.size(); i++)
        {
            components[i]->update(deltaTime);
        }
    }

    void Scene::instantiate(Component *component)
    {
        components.push_back(std::unique_ptr<Component>(component));

        component->start();
    }
}
