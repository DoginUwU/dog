#include "core/input.hpp"

void Input::key_callback(const int key, const KeyState state) {
    switch (state) {
        case KeyState::Pressed: {
            keys_down.set(key);
            break;
        }
        case KeyState::Released: {
            keys_down.reset(key);
            keys_pressed.reset(key);
            break;
        }
    }
}

void Input::mouse_pos_callback(float x, float y) {
    mouse_position = {x, y};
}

bool Input::is_key_pressed(const int key) {
    if (!is_key_down(key)) {
        return false;
    }

    if (!keys_pressed.test(key)) {
        keys_pressed.set(key);

        return true;
    }

    return false;
}


bool Input::is_key_down(const int key) {
    return keys_down.test(key);
}

bool Input::is_key_up(const int key) {
    return !keys_down.test(key);
}
