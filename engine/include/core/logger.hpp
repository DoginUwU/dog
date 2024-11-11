#pragma once

class Logger final {
public:
    static void info(const char *format, ...);

    static void error(const char *format, ...);

private:
    static void print(const char *text, const char *color);
};
