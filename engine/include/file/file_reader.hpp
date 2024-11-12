#pragma once
#include <fstream>

#include "core/logger.hpp"

class FileReader {
public:
    static std::string read(const std::string &path) {
        std::ifstream file(path.c_str());

        if (file.fail()) {
            Logger::error("Failed to open file with path: %s", path.c_str());
            return "FAILED";
        }

        const std::string source((std::istreambuf_iterator(file)), std::istreambuf_iterator<char>());

        file.close();

        return source;
    }
};
