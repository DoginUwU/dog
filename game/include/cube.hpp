#pragma once

#include <core/game_object.hpp>

#include "core/input.hpp"
#include "core/logger.hpp"

class Cube final : public GameObject {
public:
    void start() override {
        mesh->vertices = {
            -1, 1, 0,
            1, 1, 0,
            1, -1, 0,
            -1, -1, 0,
        };
        mesh->indices = {
            1, 2, 3,
            1, 3, 4
        };

        mesh->optimize();
    }

    void update() override {
        if (Input::is_key_down(KEYCODE_F)) {
            Logger::info("Apertei F :)");
        }
    }

    ~Cube() override = default;
};
