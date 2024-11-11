#pragma once
#include <core/object.hpp>

class Timer final : public Object {
public:
    void start() override {
        printf("Timer started\n");
    }

    void update() override {
        printf("Timer updated\n");
    }

    ~Timer() override = default;
};
