#pragma once
#include <string>

class WindowAPI {
public:
    virtual void create_window(int width, int height, const std::string &title) = 0;

    virtual bool should_close() = 0;
};
