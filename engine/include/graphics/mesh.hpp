#pragma once

#include <vector>

class Mesh {
public:
    virtual void update() = 0;

    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual void draw() = 0;

    virtual ~Mesh() = default;

    void optimize();

    std::vector<float> vertices;
    std::vector<unsigned int> indices;
    std::vector<float> uvs;
};
