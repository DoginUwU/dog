#include "scene.hpp"
#include "fly-camera.hpp"
#include "world.hpp"
#include "gl/input.hpp"

using namespace Dog;

class MainScene : public Scene
{
    void start()
    {
        Scene::start();

        FlyCamera *camera = new FlyCamera();
        instantiate(camera);
        instantiate(new World(camera));
    }

    void update(float deltaTime)
    {
        Scene::update(deltaTime);
    }
};
