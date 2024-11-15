#pragma once

#include <string>

#include "stb_image.h"
#include "core/logger.hpp"
#include "utils/checks.hpp"

enum class ImageType {
    PNG,
    JPG
};

struct Image {
    int width;
    int height;
    unsigned char *data;
    ImageType type;
};

class ImageReader final {
public:
    static Image read(const std::string &path) {
        int width, height, channels;

        //stbi_set_flip_vertically_on_load(true);

        const auto data = stbi_load(path.c_str(), &width, &height, &channels, 0);

        if (!data) {
            Logger::error("Failed to load texture with path: %s", path.c_str());
        }

        auto type = ImageType::JPG;

        if (Checks::ends_with(path, ".png")) {
            type = ImageType::PNG;
        }

        return Image{
            .width = width,
            .height = height,
            .data = data,
            .type = type,
        };
    }

    static void free(const Image &image) {
        stbi_image_free(image.data);
    }
};
