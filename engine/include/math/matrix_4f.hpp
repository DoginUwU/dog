#pragma once
#include <array>

#include "vector_3f.hpp"

class Matrix4F {
public:
    static Matrix4F identity();

    void translate(const Vector3F &translation);

    void scale(const Vector3F &factor);

    std::array<float, 16> elements{};
};
