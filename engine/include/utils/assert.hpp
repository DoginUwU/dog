#pragma once
#include <stdexcept>
#include <string>

class Assert {
public:
    template<typename T>
    static void check_nullptr(const T &ptr, const std::string &message) {
        if (ptr == nullptr) {
            throw std::runtime_error(message);
        }
    }
};
