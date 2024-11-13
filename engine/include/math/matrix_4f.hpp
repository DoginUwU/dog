#pragma once
#include <array>

class Matrix4F {
public:
    void identity();

    std::array<float, 16> elements{};
};
