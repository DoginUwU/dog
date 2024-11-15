#pragma once
#include <core/scene.hpp>

#include "chunk.hpp"
#include "cube.hpp"
#include "fly_camera.hpp"
#include "timer.hpp"
#include "world.hpp"
#include "file/image_reader.hpp"

class MainScene final : public Scene {
public:
    void start() override {
        const auto object_shader = GameManager::assets_library->add_shader("Object", OBJECT_VERTEX_SHADER,
                                                                           OBJECT_FRAGMENT_SHADER);
        const auto grass_texture = GameManager::assets_library->add_texture("grass", "resources/images/grass.png");
        GameManager::assets_library->add_material("Terrain1", {
                                                      .shader = object_shader,
                                                      .texture = grass_texture,
                                                  });

        add_camera(std::make_unique<FlyCamera>());
        add_object(std::make_unique<Timer>());
        add_object(std::make_unique<World>());
        add_light(std::make_unique<DirectionalLight>(DirectionalLight{
            .base = {
                .color = Vector3F{0.6f, 0.27f, 1.0f},
                .ambient_intensity = 4.0f,
                .diffuse_intensity = 1.0f,
            },
            .direction = Vector3F{5.0f, 1.0f, 1.0f},
        }));
    }

    void update(const float delta_time) override {
        Scene::update(delta_time);

        if (Input::is_key_pressed(KEYCODE_P)) {
            Engine::renderer->toggle_wireframe_mode();
        }
    }

    ~MainScene() override = default;

private:
    const std::string OBJECT_VERTEX_SHADER = "resources/shaders/object/object.vert";
    const std::string OBJECT_FRAGMENT_SHADER = "resources/shaders/object/object.frag";
};
