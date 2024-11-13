#include "math/matrix_4f.hpp"

Matrix4F Matrix4F::identity() {
    Matrix4F matrix;
    matrix.elements = {
        1.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f,
        0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 1.0f,
    };

    return matrix;
}

void Matrix4F::translate(const Vector3F &translation) {
    elements[3] += translation.x;
    elements[7] += translation.y;
    elements[11] += translation.z;
}
