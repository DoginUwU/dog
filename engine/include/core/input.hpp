#pragma once
#include <bitset>

#include "math/vector_2f.hpp"

#define KEYCODE_P 0x50
#define KEYCODE_F 0x46
#define KEYCODE_W 0x57
#define KEYCODE_A 0x41
#define KEYCODE_S 0x53
#define KEYCODE_D 0x44

enum class KeyState {
    Pressed,
    Released,
};

class Input {
public:
    static void key_callback(int key, KeyState state);

    static void mouse_pos_callback(float x, float y);

    static bool is_key_pressed(int key);

    static bool is_key_down(int key);

    static bool is_key_up(int key);

    inline static Vector2F mouse_position{0.0f, 0.0f};

private:
    inline static std::bitset<1024> keys_down = {};
    inline static std::bitset<1024> keys_pressed = {};
};

