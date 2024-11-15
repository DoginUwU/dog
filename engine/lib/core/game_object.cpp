#include <core/game_object.hpp>

#include "core/game_manager.hpp"
#include "core/light_manager.hpp"
#include "utils/assert.hpp"

void GameObject::draw() const {
    Assert::check_nullptr(material->shader, "GameObject without material shader called to draw");
    Assert::check_nullptr(material->texture, "GameObject without material texture called to draw");
    Assert::check_nullptr(mesh, "GameObject without mesh called to draw");
    Assert::check_nullptr(GameManager::active_scene->active_camera, "Camera does not exists in active scene");

    material->texture->bind();
    material->shader->bind();
    material->shader->set_uniform("model", transform.matrix);
    material->shader->set_uniform("view", GameManager::active_scene->active_camera->view);
    // TODO: Doesnt call this every tick
    material->shader->set_uniform("projection", GameManager::active_scene->active_camera->projection);

    LightManager::upload_lighting_data(material->shader, GameManager::active_scene);

    mesh->bind();
    mesh->draw();
    mesh->unbind();

    material->shader->unbind();
    material->texture->unbind();
}
