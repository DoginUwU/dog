#include "chunk.hpp"
#include "gl/input.hpp"

#include <iostream>
#include <math.h>
#include <chrono>

Chunk::Chunk(glm::vec3 position, const siv::PerlinNoise *perlinNoise)
{
    setSize(position, position + glm::vec3(VoxelData::CHUNK_SIZE, VoxelData::CHUNK_SIZE_Y, VoxelData::CHUNK_SIZE));

    this->perlinNoise = perlinNoise;
    this->transform.setPosition(position);

    createMesh();
}

Chunk::~Chunk() {}

void Chunk::start()
{
    Object::start();
}

void Chunk::update(float deltaTime)
{
    Object::update(deltaTime);
}

void Chunk::createMesh()
{
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    mesh.vertices.reserve(VoxelData::CHUNK_SIZE * VoxelData::CHUNK_SIZE_Y * VoxelData::CHUNK_SIZE * 24);
    mesh.indices.reserve(VoxelData::CHUNK_SIZE * VoxelData::CHUNK_SIZE_Y * VoxelData::CHUNK_SIZE * 36);

    for (double x = 0; x < VoxelData::CHUNK_SIZE; x += VoxelData::VOXEL_SIZE)
    {
        for (double y = 0; y < VoxelData::CHUNK_SIZE_Y; y += VoxelData::VOXEL_SIZE)
        {
            for (double z = 0; z < VoxelData::CHUNK_SIZE; z += VoxelData::VOXEL_SIZE)
            {
                double generatedY = getBlockHeight(x, z);
                createBlock(x, generatedY - y, z);
            }
        }
    }

    mesh.optimize();

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();

    std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;
}

void Chunk::createBlock(double x, double y, double z)
{
    uint_least8_t R = 0;
    uint_least8_t G = rand() % 255;
    uint_least8_t B = 0;

    glm::vec3 blockPos = glm::vec3(x, y, z);

    for (int p = 0; p < VoxelData::faces.size(); p++)
    {
        glm::vec3 facePos = blockPos + VoxelData::faces[p];

        if (!isFaceVisible(facePos.x, facePos.y, facePos.z, static_cast<Direction>(p)))
        {
            continue;
        }

        for (uint32_t i = 0; i < 4; i++)
        {
            glm::vec3 position = VoxelData::vertices[VoxelData::indices[p][i]] + blockPos;
            mesh.vertices.push_back({{position.x, position.y, position.z},
                                     {R, G, B}});
        }

        mesh.indices.push_back(vertexIndex + 0);
        mesh.indices.push_back(vertexIndex + 1);
        mesh.indices.push_back(vertexIndex + 2);
        mesh.indices.push_back(vertexIndex + 2);
        mesh.indices.push_back(vertexIndex + 3);
        mesh.indices.push_back(vertexIndex + 0);

        vertexIndex += 4;
    }
}

bool Chunk::isFaceVisible(double x, double y, double z, Direction direction)
{
    if (x < 0 || y < 0 || z < 0)
    {
        return false;
    }

    if (x > VoxelData::CHUNK_SIZE || y > VoxelData::CHUNK_SIZE_Y + 1 || z > VoxelData::CHUNK_SIZE)
    {
        return false;
    }

    switch (direction)
    {
    case FRONT:
        return getBlockHeight(x, z) < y;
    case BACK:
        return getBlockHeight(x, z) < y;
    case RIGHT:
        return getBlockHeight(x, z) < y;
    case LEFT:
        return getBlockHeight(x, z) < y;
    case TOP:
        return getBlockHeight(x, z) < y;
    // TODO: Find a way to check bottom face visibility
    case BOTTOM:
        return false;
    default:
        return false;
    }
}

double Chunk::getBlockHeight(double x, double z)
{
    int xKey = std::round(x * 10);
    int zKey = std::round(z * 10);

    RoundedCoords coords = {xKey, zKey};

    if (blockHeights.find(coords) != blockHeights.end())
    {
        return blockHeights[coords];
    }

    glm::vec3 heightPos = glm::vec3(x, 0, z) + transform.getPosition();
    const double y = perlinNoise->octave2D_01(heightPos.x * 0.1, heightPos.z * 0.1, 6) * (VoxelData::CHUNK_SIZE_Y / VoxelData::VOXEL_SIZE);

    int yInt = std::round(y);

    double value = yInt * VoxelData::VOXEL_SIZE;

    blockHeights[coords] = value;

    return value;
}
