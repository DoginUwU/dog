#include "scene.hpp"
#include "cube.hpp"

using namespace Dog;

class MainScene : public Scene
{
    void start()
    {
        Scene::start();

        instantiate(new Cube());
    }
};
