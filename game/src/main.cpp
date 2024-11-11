#include <engine.hpp>

#include "main_scene.hpp"

int main() {
    const Engine engine;

    engine.game_manager->set_active_scene(std::make_unique<MainScene>());

    engine.loop();

    return EXIT_SUCCESS;
}
