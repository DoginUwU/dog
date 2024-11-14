#include "core/input.hpp"

void Input::key_callback(const int key, const KeyState state) {
    switch (state) {
        case KeyState::Pressed: {
            keys_pressed.set(key);
            break;
        }
        case KeyState::Released: {
            keys_pressed.reset(key);
            break;
        }
    }
}

void Input::mouse_pos_callback(float x, float y) {
    mouse_position = {x, y};
}

bool Input::is_key_down(const int key) {
    return keys_pressed.test(key);
}

bool Input::is_key_up(const int key) {
    return !keys_pressed.test(key);
}
