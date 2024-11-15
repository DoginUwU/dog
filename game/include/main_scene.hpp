#pragma once
#include <core/scene.hpp>

#include "chunk.hpp"
#include "cube.hpp"
#include "fly_camera.hpp"
#include "timer.hpp"
#include "file/image_reader.hpp"

class MainScene final : public Scene {
public:
    void start() override {
        const auto object_shader = GameManager::assets_library->add_shader("Object", OBJECT_VERTEX_SHADER,
                                                                           OBJECT_FRAGMENT_SHADER);
        GameManager::assets_library->add_material("Terrain1", {
                                                      .shader = object_shader
                                                  });

        auto data = ImageReader::read("resources/images/grass.png");

        add_camera(std::make_unique<FlyCamera>());
        add_object(std::make_unique<Timer>());
        add_object(std::make_unique<Chunk>());
    }

    void update(const float delta_time) override {
        Scene::update(delta_time);

        if (Input::is_key_pressed(KEYCODE_P)) {
            Engine::renderer->toggle_wireframe_mode();
        }
    }

    ~MainScene() override = default;

private:
    const std::string OBJECT_VERTEX_SHADER = "resources/shaders/object.vert";
    const std::string OBJECT_FRAGMENT_SHADER = "resources/shaders/object.frag";
};
