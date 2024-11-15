#include <core/game_manager.hpp>

GameManager::GameManager() {
    assets_library = std::make_unique<AssetsLibrary>();
    time = std::make_unique<Time>();

    time->start();
}


void GameManager::set_active_scene(std::unique_ptr<Scene> scene) {
    active_scene = std::move(scene);
    active_scene->start();
}

void GameManager::update() {
    if (active_scene == nullptr) return;

    time->update();
    active_scene->update(time->get_delta_time());
}
