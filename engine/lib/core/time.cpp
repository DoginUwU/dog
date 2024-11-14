#include "core/time.hpp"

void Time::start() {
    last_time = std::chrono::high_resolution_clock::now();
}

void Time::update() {
    const auto current_time = std::chrono::high_resolution_clock::now();
    delta_time = std::chrono::duration<float>(current_time - last_time).count();
    last_time = current_time;
}

float Time::get_delta_time() const {
    return delta_time;
}
