#pragma once
#include "core/game_object.hpp"

class Monkey final : public GameObject {
public:
    void start() override {
        material = GameManager::assets_library->get_material("Terrain1");
        mesh = Engine::graphics_factory->create_mesh();

        GameObject::start();

        ObjectReader::read_obj(mesh, "resources/models/test.obj");

        mesh->update();

        transform.set_position(Vector3F{0.0, 1.0, 0.0});
    }

    void update(const float delta_time) override {
        GameObject::update(delta_time);
    }
};

