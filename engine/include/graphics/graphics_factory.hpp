#pragma once
#include <memory>

#include "window/window_api.hpp"

class GraphicsFactory {
public:
    virtual std::unique_ptr<WindowAPI> create_window_api() = 0;

    virtual ~GraphicsFactory() {
    };
};
