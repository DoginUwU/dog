#include "chunk.hpp"
#include "voxel.hpp"

Chunk::Chunk(glm::vec3 position, const siv::PerlinNoise *perlinNoise)
{
    this->perlinNoise = perlinNoise;
    this->transform.setPosition(position);
    createMesh();
}

Chunk::~Chunk()
{
}

void Chunk::start()
{
}

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
            glm::vec3 heightPos = glm::vec3(x, 0, z) + transform.getPosition();
            const float height = perlinNoise->octave2D_01(heightPos.x * 0.05, heightPos.z * 0.05, 6) * VoxelData::CHUNK_SIZE_Y;
            createBlock(x, height, z);
        }
    }
}

void Chunk::createBlock(float x, float y, float z)
{
    uint_least8_t R = 0;
    uint_least8_t G = rand() % 255;
    uint_least8_t B = 0;

    for (int p = 0; p < VoxelData::faces.size(); p++)
    {
        glm::vec3 facePos = glm::vec3(x, y, z) + VoxelData::getCorrectedNormal(VoxelData::faces[p]);

        // TODO: Fix P = 3
        if (!isBlockVisible(facePos.x, facePos.y, facePos.z) || p == 3)
        {
            continue;
        }

        for (uint32_t i = 0; i < 4; i++)
        {
            glm::vec3 position = VoxelData::getCorrectedNormal(VoxelData::vertices[VoxelData::indices[p][i]]) + glm::vec3(x, y, z);
            mesh.vertices.push_back({{position.x, position.y, position.z},
                                     {R, G, B}});
        }

        mesh.indices.push_back(vertexIndex);
        mesh.indices.push_back(vertexIndex + 1);
        mesh.indices.push_back(vertexIndex + 2);
        mesh.indices.push_back(vertexIndex + 2);
        mesh.indices.push_back(vertexIndex + 1);
        mesh.indices.push_back(vertexIndex + 3);

        vertexIndex += 4;
    }
}

bool Chunk::isBlockVisible(float x, float y, float z)
{
    if (x < 0 || y < 0 || z < 0)
    {
        return false;
    }

    if (x > VoxelData::CHUNK_SIZE || y > VoxelData::CHUNK_SIZE_Y || z > VoxelData::CHUNK_SIZE)
    {
        return false;
    }

    return true;
}
