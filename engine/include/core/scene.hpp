#pragma once
#include <vector>
#include <memory>

#include "camera.hpp"
#include "object.hpp"

class Scene : public Object {
public:
    void add_object(std::unique_ptr<Object> object);

    void add_camera(std::unique_ptr<Camera> camera);

    void update(float delta_time) override;

    ~Scene() override = default;

    std::unique_ptr<Camera> active_camera = nullptr;

private:
    std::vector<std::unique_ptr<Object> > active_objects;
};
