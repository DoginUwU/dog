#pragma once
#include <memory>

#include "material.hpp"
#include "object.hpp"
#include "transform.hpp"
#include "graphics/mesh.hpp"

class GameObject : public Object {
public:
    void awake() override {
    }

    void start() override {
    }

    void update(const float delta_time) override {
        draw();
    }

    void draw() const;

    ~GameObject() override = default;

protected:
    Transform transform;

    std::unique_ptr<Mesh> mesh = nullptr;
    std::shared_ptr<Material> material = nullptr;
};
