#pragma once
#include <bitset>

#define KEYCODE_F 0x46

enum class KeyState {
    Pressed,
    Released,
};

class Input {
public:
    static void key_callback(int key, KeyState state);

    static bool is_key_down(int key);

    static bool is_key_up(int key);

private:
    inline static std::bitset<1024> keys_pressed = {};
};

