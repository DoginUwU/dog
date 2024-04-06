#ifndef VOXEL_HPP
#define VOXEL_HPP

#include <glm/glm.hpp>

enum Direction
{
    FRONT,
    BACK,
    RIGHT,
    LEFT,
    TOP,
    BOTTOM
};

class VoxelData
{
public:
    static constexpr double VOXEL_SIZE = 0.2f;

    inline static std::vector<glm::vec3> vertices = {
        {0, 0, 0},                                        // 0
        {1 * VOXEL_SIZE, 0, 0},                           // 1
        {1 * VOXEL_SIZE, 1 * VOXEL_SIZE, 0},              // 2
        {0, 1 * VOXEL_SIZE, 0},                           // 3
        {0, 0, 1 * VOXEL_SIZE},                           // 4
        {1 * VOXEL_SIZE, 0, 1 * VOXEL_SIZE},              // 5
        {1 * VOXEL_SIZE, 1 * VOXEL_SIZE, 1 * VOXEL_SIZE}, // 6
        {0, 1 * VOXEL_SIZE, 1 * VOXEL_SIZE}               // 7
    };

    static constexpr uint8_t indices[6][4] = {
        {0, 1, 2, 3}, // Front
        {5, 4, 7, 6}, // Back
        {6, 2, 1, 5}, // Right
        {4, 0, 3, 7}, // Left
        {3, 2, 6, 7}, // Top
        {4, 5, 1, 0}  // Bottom
    };

    inline static std::vector<glm::vec3> faces = {
        {0, 0, -1 * VOXEL_SIZE}, // Front
        {0, 0, 1 * VOXEL_SIZE},  // Back
        {1 * VOXEL_SIZE, 0, 0},  // Right
        {-1 * VOXEL_SIZE, 0, 0}, // Left
        {0, 1 * VOXEL_SIZE, 0},  // Top
        {0, -1 * VOXEL_SIZE, 0}  // Bottom
    };

    // static constexpr int_fast8_t normals[6][3] = {

    // };

    static constexpr double CHUNK_SIZE = 16;
    static constexpr double CHUNK_SIZE_Y = 0.2f;
    static const uint_least8_t RENDER_DISTANCE = 8;
    static const uint16_t WORLD_SIZE = 12;
    static const uint16_t WORLD_SIZE_IN_CHUNK_SIZE = WORLD_SIZE * CHUNK_SIZE;
};
#endif
