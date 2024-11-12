#pragma once
#include <memory>

#include "object.hpp"
#include "graphics/mesh.hpp"
#include "graphics/shader.hpp"

class GameObject : public Object {
public:
    void start() override {
    };

    void update() override {
        draw();
    };

    void draw() const;

    void after_start() override;

    ~GameObject() override = default;

protected:
    std::unique_ptr<Mesh> mesh = nullptr;
    std::shared_ptr<Shader> shader = nullptr;
};
