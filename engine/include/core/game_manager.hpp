#pragma once
#include <memory>

#include "scene.hpp"

class GameManager final {
public:
    void set_active_scene(std::unique_ptr<Scene> scene);

    void update() const;

private:
    std::unique_ptr<Scene> active_scene;
};
