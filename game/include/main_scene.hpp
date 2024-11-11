#pragma once
#include <core/scene.hpp>

#include "cube.hpp"
#include "timer.hpp"

class MainScene final : public Scene {
public:
    void start() override {
        add_object(std::make_unique<Timer>());
        add_object(std::make_unique<Cube>());
    }

    void update() override {
        Scene::update();
    }

    ~MainScene() override = default;
};
