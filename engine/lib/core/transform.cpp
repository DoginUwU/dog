#include "core/transform.hpp"

Transform::Transform() {
}

void Transform::translate(const Vector3F &translation) {
    matrix.translate(translation);
}
