#pragma once
#include <core/scene.hpp>

#include "timer.hpp"

class MainScene final : public Scene {
public:
    void start() override {
        add_object(std::make_unique<Timer>());
    }

    void update() override {
        Scene::update();
    }

    ~MainScene() override = default;
};
