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
    material->shader->set_uniform("camera_position", GameManager::active_scene->active_camera->position);

    material->shader->set_uniform("material.ambient", material->ambient);
    material->shader->set_uniform("material.diffuse", material->diffuse);
    material->shader->set_uniform("material.specular", material->specular);
    material->shader->set_uniform("material.shininess", material->shininess);

    LightManager::upload_lighting_data(material->shader, GameManager::active_scene);

    mesh->bind();
    mesh->draw();
    mesh->unbind();

    material->shader->unbind();
    material->texture->unbind();
}
