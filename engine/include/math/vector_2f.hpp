#pragma once
#include <glm/glm.hpp>

class Vector2F {
public:
    // TODO: Make my only math library
    glm::vec2 data;

    Vector2F() : data(0.0f, 0.0f) {
    }

    Vector2F(const float x, const float y) : data(x, y) {
    }

    [[nodiscard]] float x() const { return data.x; }
    [[nodiscard]] float y() const { return data.y; }
};
