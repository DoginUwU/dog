#pragma once
#include <core/object.hpp>

#include "core/logger.hpp"

class Timer final : public Object {
public:
    void start() override {
    }

    void update() override {
        Logger::info("Timer ID %d", 1);
    }

    ~Timer() override = default;
};
