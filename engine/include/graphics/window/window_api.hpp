#pragma once
#include <string>

typedef void (*WindowProcAddress)(void);

class WindowAPI {
public:
    virtual void create_window(int width, int height, const std::string &title) = 0;

    virtual void update() = 0;

    virtual bool should_close() = 0;

    virtual WindowProcAddress get_process_address(const char *name) = 0;

    virtual ~WindowAPI() = default;
};
