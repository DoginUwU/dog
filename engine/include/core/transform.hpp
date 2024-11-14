#pragma once
#include "math/matrix_4f.hpp"
#include "math/vector_3f.hpp"

class Transform {
public:
    Transform();

    [[nodiscard]] Vector3F position() const;

    void translate(const Vector3F &translation);

    void scale(const Vector3F &factor);

    Matrix4F matrix = Matrix4F(1.0f);
};
