#pragma once
#include <memory>

#include "object.hpp"
#include "graphics/mesh.hpp"

class GameObject : public Object {
public:
    void start() override {
    };

    void update() override {
    };

    ~GameObject() override = default;

protected:
    std::unique_ptr<Mesh> mesh = std::make_unique<Mesh>();
};
