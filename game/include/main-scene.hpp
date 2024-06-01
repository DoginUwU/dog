#include "scene.hpp"
#include "fly-camera.hpp"
#include "world.hpp"

using namespace Dog;

class MainScene : public Scene
{
    void start() override
    {
        Scene::start();

        auto *camera = new FlyCamera();
        instantiate(camera);
        instantiate(new World(camera));
    }

    void update(const float deltaTime)
    {
        Scene::update(deltaTime);
    }
};
