#pragma once
#include "base_light.hpp"

struct DirectionalLight {
    BaseLight base;
    Vector3F direction;
};
