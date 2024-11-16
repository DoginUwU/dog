#pragma once
#include "math/vector_3f.hpp"

struct BaseLight {
    Vector3F color;
    float ambient{};
    float diffuse{};
};
