#include "engine.hpp"
#include "main-scene.hpp"

#include <exception>
#include <iostream>

using namespace Dog;

int main(int, char **)
{
    try
    {
        Engine engine;
        MainScene mainScene;

        engine.setActiveScene(&mainScene);
        engine.run();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}
