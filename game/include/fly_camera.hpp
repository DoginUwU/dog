#pragma once

#include "core/camera.hpp"
#include "core/input.hpp"

class FlyCamera final : public Camera {
public:
    void start() override {
        Camera::start();
    }

    void update(const float delta_time) override {
        Camera::update(delta_time);

        process_input(delta_time);
        process_mouse(Input::mouse_position.x(), Input::mouse_position.y());
    }

    void process_input(const float delta_time) {
        const float velocity = speed * delta_time;

        if (Input::is_key_down(KEYCODE_W)) {
            position += front * velocity;
        }

        if (Input::is_key_down(KEYCODE_S)) {
            position -= front * velocity;
        }

        if (Input::is_key_down(KEYCODE_A)) {
            position -= Vector3F::normalize(Vector3F::cross(front, up)) * velocity;
        }

        if (Input::is_key_down(KEYCODE_D)) {
            position += Vector3F::normalize(Vector3F::cross(front, up)) * velocity;
        }
    }

    void process_mouse(const float x, const float y) {
        float x_offset = x - last_x;
        float y_offset = last_y - y;

        last_x = x;
        last_y = y;

        x_offset *= sensitivity;
        y_offset *= sensitivity;

        yaw += x_offset;
        pitch += y_offset;

        if (pitch > 89.0f) {
            pitch = 89.0f;
        }

        if (pitch < -89.0f) {
            pitch = -89.0f;
        }

        const Vector3F direction{
            std::cos(Vector3F::radians(yaw)) * std::cos(Vector3F::radians(pitch)),
            std::sin(Vector3F::radians(pitch)),
            std::sin(Vector3F::radians(yaw)) * std::cos(Vector3F::radians(pitch)),
        };

        front = Vector3F::normalize(direction);
    }

private:
    float speed = 5.0f;
    float last_y = 0.0f;
    float last_x = 0.0f;
    float sensitivity = 0.1f;
    float yaw = 0.0f;
    float pitch = 0.0f;
};
