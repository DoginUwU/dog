#include <core/game_manager.hpp>

GameManager::GameManager() {
    shader_library = std::make_unique<ShaderLibrary>();
}


void GameManager::set_active_scene(std::unique_ptr<Scene> scene) {
    active_scene = std::move(scene);
    active_scene->start();
}

void GameManager::update() const {
    if (active_scene == nullptr) return;

    active_scene->update();
}

