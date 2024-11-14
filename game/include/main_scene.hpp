#pragma once
#include <core/scene.hpp>

#include "cube.hpp"
#include "fly_camera.hpp"
#include "timer.hpp"

class MainScene final : public Scene {
public:
    void start() override {
        GameManager::shader_library->add("Object", OBJECT_VERTEX_SHADER, OBJECT_FRAGMENT_SHADER);

        add_camera(std::make_unique<FlyCamera>());
        add_object(std::make_unique<Timer>());
        add_object(std::make_unique<Cube>());
    }

    void update(const float delta_time) override {
        Scene::update(delta_time);
    }

    ~MainScene() override = default;

private:
    inline static const std::string OBJECT_VERTEX_SHADER = "resources/shaders/object.vert";
    inline static const std::string OBJECT_FRAGMENT_SHADER = "resources/shaders/object.frag";
};
