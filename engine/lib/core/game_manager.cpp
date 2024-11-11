#include <core/game_manager.hpp>

void GameManager::set_active_scene(std::unique_ptr<Scene> scene) {
    active_scene = std::move(scene);
    active_scene->start();
}

void GameManager::update() const {
    if (active_scene == nullptr) return;

    active_scene->update();
}

