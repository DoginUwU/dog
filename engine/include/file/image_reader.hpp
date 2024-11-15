#pragma once

#include <string>

#include "stb_image.h"
#include "core/logger.hpp"

struct Image {
    int width;
    int height;
    unsigned char *data;
};

class ImageReader final {
public:
    static Image read(const std::string &path) {
        int width, height;
        const auto data = stbi_load(path.c_str(), &width, &height, nullptr, 0);

        if (!data) {
            Logger::error("Failed to load texture with path: %s", path.c_str());
        }

        return Image{
            .width = width,
            .height = height,
            .data = data,
        };
    }

    static void free(const Image &image) {
        stbi_image_free(image.data);
    }
};
