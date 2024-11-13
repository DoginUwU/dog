#pragma once
#include "math/matrix_4f.hpp"
#include "math/vector_3f.hpp"

class Transform {
public:
    Transform();

    void translate(const Vector3F &translation);

    Matrix4F matrix = Matrix4F::identity();
};
