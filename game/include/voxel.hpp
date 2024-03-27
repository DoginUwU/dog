#ifndef VOXEL_HPP
#define VOXEL_HPP

#include <glm/glm.hpp>

class VoxelData
{
public:
    inline static std::vector<glm::vec3> vertices = {
        {0, 0, 0},
        {1, 0, 0},
        {1, 1, 0},
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 1},
        {1, 1, 1},
        {0, 1, 1},
    };
    inline static std::vector<glm::vec3> faces = {
        {0, 0, -1},
        {0, 0, 1},
        {0, 1, 0},
        {0, -1, 0},
        {-1, 0, 0},
        {1, 0, 0},
    };
    static constexpr uint8_t indices[6][4] = {
        {0, 3, 1, 2},
        {5, 6, 4, 7},
        {3, 7, 2, 6},
        {1, 5, 0, 4},
        {4, 7, 0, 3},
        {1, 2, 5, 6},
    };
    static constexpr int_fast8_t normals[6][3] = {
        {0, 0, -1},
        {0, 0, 1},
        {0, 1, 0},
        {0, -1, 0},
        {-1, 0, 0},
        {1, 0, 0},
    };
    static glm::vec3 getCorrectedNormal(glm::vec3 normal)
    {
        return normal * VOXEL_SIZE;
    }

    static constexpr float VOXEL_SIZE = 0.1f;
    static const uint_least8_t CHUNK_SIZE = 6;
    static const uint_least8_t CHUNK_SIZE_Y = 2;
    static const uint_least8_t RENDER_DISTANCE = 4;
    static const uint16_t WORLD_SIZE = 100;
    static const uint16_t WORLD_SIZE_IN_CHUNK_SIZE = WORLD_SIZE * CHUNK_SIZE;
};
#endif
