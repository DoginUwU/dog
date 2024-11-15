#pragma once

#include "core/game_object.hpp"
#include "core/input.hpp"

class Cube final : public GameObject {
public:
    explicit Cube(const Vector3F &initial_pos) {
        transform.translate(initial_pos);
    }

    void awake() override {
        shader = GameManager::shader_library->get("Object");
        mesh = Engine::graphics_factory->create_mesh();

        mesh->vertices = {
            1.0f, 0.0f, 1.0f,
            1.0f, 0.0f, -1.0f,
            -1.0f, 0.0f, -1.0f,
            -1.0f, 0.0f, 1.0f,
        };
        mesh->indices = {
            0, 1, 3,
            1, 2, 3
        };

        mesh->optimize();
        mesh->update();
    }

    void update(const float delta_time) override {
        GameObject::update(delta_time);

        if (Input::is_key_down(KEYCODE_F)) {
            transform.translate(Vector3F{0.0f, 0.0f, -0.1f});
        }
    }

    ~Cube() override = default;
};
