#pragma once
#include <vector>

class Mesh {
public:
    Mesh();

    ~Mesh();

    void optimize();

    std::vector<float> vertices;
    std::vector<unsigned int> indices;
};
