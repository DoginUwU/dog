#include <core/scene.hpp>

void Scene::add_object(std::unique_ptr<Object> object) {
    object->awake();
    object->start();
    active_objects.push_back(std::move(object));
}

void Scene::add_camera(std::unique_ptr<Camera> camera) {
    camera->awake();
    camera->start();
    active_camera = std::move(camera);
}

void Scene::add_light(std::unique_ptr<DirectionalLight> directional_light) {
    directional_lights.push_back(std::move(directional_light));
}

void Scene::update(const float delta_time) {
    if (active_camera != nullptr) {
        active_camera->update(delta_time);
    }

    for (const auto &object: active_objects) {
        object->update(delta_time);
    }
}
