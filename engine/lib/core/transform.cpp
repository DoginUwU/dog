#include "core/transform.hpp"

Transform::Transform() = default;

void Transform::set_position(const Vector3F &new_position) {
    matrix.set_position(new_position);
}


void Transform::translate(const Vector3F &translation) {
    matrix.translate(translation);
}

void Transform::scale(const Vector3F &factor) {
}

Vector3F Transform::position() const {
    return Vector3F{matrix.data[3].x, matrix.data[3].y, matrix.data[3].z};
}
