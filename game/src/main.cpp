#include <engine.hpp>

#include "main_scene.hpp"

int main() {
    std::make_unique<Engine>();
    GameManager::set_active_scene(std::make_unique<MainScene>());
    Engine::loop();

    return EXIT_SUCCESS;
}
