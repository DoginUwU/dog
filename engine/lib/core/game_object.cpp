#include <core/game_object.hpp>

#include "core/game_manager.hpp"
#include "core/light_manager.hpp"
#include "utils/assert.hpp"

void GameObject::draw() const {
    Assert::check_nullptr(material->shader, "GameObject without material shader called to draw");
    Assert::check_nullptr(mesh, "GameObject without mesh called to draw");
    Assert::check_nullptr(GameManager::active_scene->active_camera, "Camera does not exists in active scene");

    if (material->texture != nullptr) {
        material->texture->bind();
    }

    material->shader->bind();
    material->shader->set_uniform("model", transform.matrix);
    material->shader->set_uniform("view", GameManager::active_scene->active_camera->view);

    material->shader->set_uniform("has_texture", material->texture != nullptr);
    material->shader->set_uniform("has_colors", !mesh->colors.empty());

    // TODO: Doesnt call this every time
    material->shader->set_uniform("projection", GameManager::active_scene->active_camera->projection);
    material->shader->set_uniform("camera_position", GameManager::active_scene->active_camera->position);

    // TODO: Doesnt send this every time (only if updates)
    material->shader->set_uniform("material.ambient", material->ambient);
    material->shader->set_uniform("material.diffuse", material->diffuse);
    material->shader->set_uniform("material.specular", material->specular);
    material->shader->set_uniform("material.shininess", material->shininess);

    LightManager::upload_lighting_data(material->shader, GameManager::active_scene);

    mesh->bind();
    mesh->draw();
    mesh->unbind();

    material->shader->unbind();

    if (material->texture != nullptr) {
        material->texture->unbind();
    }
}
