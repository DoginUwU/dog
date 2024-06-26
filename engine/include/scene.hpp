#ifndef SCENE_HPP
#define SCENE_HPP

#include "component.hpp"
#include "camera.hpp"

#include <vector>
#include <memory>

namespace Dog
{
    class Scene
    {
    public:
        Scene();
        ~Scene();

        void update(float deltaTime) const;
        virtual void start();

        void instantiate(Component *component);
        void destroy(const Component *component);

    private:
        std::vector<std::unique_ptr<Component>> components;
        Camera *mainCamera{};
    };
}
#endif
