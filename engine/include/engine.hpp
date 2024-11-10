#pragma once

#include <memory>
#include "graphics/window/window_api.hpp"

class Engine {
public:
    Engine();

    void loop() const;

private:
    std::unique_ptr<WindowAPI> window;
};
