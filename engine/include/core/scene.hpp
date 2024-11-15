#pragma once
#include <vector>
#include <memory>

#include "camera.hpp"
#include "object.hpp"
#include "graphics/light/directional_light.hpp"

class Scene : public Object {
public:
    void add_object(std::unique_ptr<Object> object);

    void add_camera(std::unique_ptr<Camera> camera);

    void add_light(std::unique_ptr<DirectionalLight> directional_light);

    void update(float delta_time) override;

    ~Scene() override = default;

    std::unique_ptr<Camera> active_camera = nullptr;
    std::vector<std::unique_ptr<DirectionalLight> > directional_lights;

private:
    std::vector<std::unique_ptr<Object> > active_objects;
};
