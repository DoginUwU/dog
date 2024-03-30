#include "chunk.hpp"
#include "gl/input.hpp"

#include <iostream>

Chunk::Chunk(glm::vec3 position, const siv::PerlinNoise *perlinNoise)
{
    setSize(position, position + glm::vec3(VoxelData::CHUNK_SIZE, VoxelData::CHUNK_SIZE_Y, VoxelData::CHUNK_SIZE));

    this->perlinNoise = perlinNoise;
    this->transform.setPosition(position);

    createMesh();
}

Chunk::~Chunk() {}

void Chunk::start() {}

void Chunk::update(float deltaTime)
{
    Object::update(deltaTime);
}

void Chunk::createMesh()
{
    for (float x = 0; x < VoxelData::CHUNK_SIZE; x += VoxelData::VOXEL_SIZE)
    {
        for (float z = 0; z < VoxelData::CHUNK_SIZE; z += VoxelData::VOXEL_SIZE)
        {
            float y = getBlockHeight(x, z);
            createBlock(x, y, z);
        }
    }

    mesh.optimize();
}

void Chunk::createBlock(float x, float y, float z)
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

bool Chunk::isFaceVisible(float x, float y, float z, Direction direction)
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
        return getBlockHeight(x, z - VoxelData::VOXEL_SIZE) < y;
    case BACK:
        return getBlockHeight(x, z + VoxelData::VOXEL_SIZE) < y;
    case RIGHT:
        return getBlockHeight(x + VoxelData::VOXEL_SIZE, z) < y;
    case LEFT:
        return getBlockHeight(x - VoxelData::VOXEL_SIZE, z) < y;
    case TOP:
        return getBlockHeight(x, z) < y;
    // TODO: Find a way to check bottom face visibility
    case BOTTOM:
        return false;
    default:
        return false;
    }
}

float Chunk::getBlockHeight(float x, float z)
{
    glm::vec3 heightPos = glm::vec3(x, 0, z) + transform.getPosition();
    const float y = perlinNoise->octave2D_01(heightPos.x * 0.1, heightPos.z * 0.1, 6) * VoxelData::CHUNK_SIZE_Y;

    return y;
}
