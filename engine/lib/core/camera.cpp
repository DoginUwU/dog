#include "core/camera.hpp"

void Camera::start() {
    // TODO: Grab window size (and update if windows resize)
    projection.perspective(90.0f, 800.0f / 600.0f, 0.1f, 1000.0f);
}

void Camera::update(float delta_time) {
    view.look_at(position, position + front, up);
}
