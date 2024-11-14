#include <core/game_object.hpp>

#include "core/game_manager.hpp"
#include "utils/assert.hpp"

void GameObject::draw() const {
    Assert::check_nullptr(shader, "GameObject without shader called to draw");
    Assert::check_nullptr(mesh, "GameObject without mesh called to draw");
    Assert::check_nullptr(GameManager::active_scene->active_camera, "Camera does not exists in active scene");

    shader->bind();
    shader->set_uniform("model", transform.matrix);
    shader->set_uniform("view", GameManager::active_scene->active_camera->view);
    // TODO: Doesnt call this every tick
    shader->set_uniform("projection", GameManager::active_scene->active_camera->projection);

    mesh->bind();
    mesh->draw();
    mesh->unbind();

    shader->unbind();
}
