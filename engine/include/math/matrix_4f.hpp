#pragma once
#include <array>

#include "vector_3f.hpp"

class Matrix4F {
public:
    static Matrix4F identity();

    void translate(const Vector3F &translation);

    //Matrix4F operator+(const Matrix4F &other) const;

    std::array<float, 16> elements{};
};
