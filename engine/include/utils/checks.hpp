#pragma once
#include <string>

class Checks {
public:
    static bool ends_with(const std::string &value, const std::string &ends) {
        if (ends.size() > value.size()) {
            return false;
        }

        return std::equal(ends.rbegin(), ends.rend(), value.rbegin());
    }
};
