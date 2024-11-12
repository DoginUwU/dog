#include <core/scene.hpp>

void Scene::add_object(std::unique_ptr<Object> object) {
    object->start();
    object->after_start();
    active_objects.push_back(std::move(object));
}

void Scene::update() {
    for (const auto &object: active_objects) {
        object->update();
    }
}
