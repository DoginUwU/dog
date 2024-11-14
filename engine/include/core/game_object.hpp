#pragma once
#include <memory>

#include "object.hpp"
#include "transform.hpp"
#include "graphics/mesh.hpp"
#include "graphics/shader.hpp"

class GameObject : public Object {
public:
    void awake() override {
    }

    void start() override {
    }

    void update(float delta_time) override {
        draw();
    }

    void draw() const;

    ~GameObject() override = default;

protected:
    Transform transform;

    std::unique_ptr<Mesh> mesh = nullptr;
    std::shared_ptr<Shader> shader = nullptr;
};
