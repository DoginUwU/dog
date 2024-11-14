#pragma once
#include <core/object.hpp>

#include "core/logger.hpp"

class Timer final : public Object {
public:
    void start() override {
    }

    void update(float delta_time) override {
    }

    ~Timer() override = default;
};
