#pragma once

#include <chrono>

class Time final {
public:
    void start();

    void update();

    float get_delta_time() const;

private:
    std::chrono::high_resolution_clock::time_point last_time;
    std::chrono::high_resolution_clock::time_point start_time;

    float delta_time{.0f};
};
