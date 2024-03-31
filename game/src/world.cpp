#include "world.hpp"
#include "engine.hpp"

#include <iostream>
#include <math.h>

World::World(Dog::Camera *camera)
{
    this->camera = camera;

    createChunk(0, 0);
    // createChunk(1, 0);
    // createChunk(0, 1);
    createChunk(1, 1);
    // updateChunksAroundPlayer();
}

World::~World()
{
}

void World::start()
{
}

void World::update(float deltaTime)
{
    // updateChunksAroundPlayer();
}

void World::updateChunksAroundPlayer()
{
    glm::vec3 playerPosition = camera->position;

    uint16_t playerChunkX = playerPosition.x / VoxelData::CHUNK_SIZE;
    uint16_t playerChunkZ = playerPosition.z / VoxelData::CHUNK_SIZE;

    uint16_t playerMinChunkX = std::max(0, (int)playerChunkX - VoxelData::RENDER_DISTANCE);
    uint16_t playerMinChunkZ = std::max(0, (int)playerChunkZ - VoxelData::RENDER_DISTANCE);
    uint16_t playerMaxChunkX = playerChunkX + VoxelData::RENDER_DISTANCE;
    uint16_t playerMaxChunkZ = playerChunkZ + VoxelData::RENDER_DISTANCE;

    for (uint16_t x = playerMinChunkX; x < playerMaxChunkX; x++)
    {
        for (uint16_t z = playerMinChunkZ; z < playerMaxChunkZ; z++)
        {
            std::cout << "Chunk: " << x << ", " << z << std::endl;

            if (chunks[x][z] == nullptr)
            {
                createChunk(x, z);
                activeChunks.push_back(chunks[x][z]);
            }
        }
    }

    for (auto chunk : activeChunks)
    {
        if (chunk == nullptr)
        {
            continue;
        }

        uint16_t chunkX = chunk->transform.getPosition().x / VoxelData::CHUNK_SIZE;
        uint16_t chunkZ = chunk->transform.getPosition().z / VoxelData::CHUNK_SIZE;

        if (chunkX < playerMinChunkX || chunkX >= playerMaxChunkX || chunkZ < playerMinChunkZ || chunkZ >= playerMaxChunkZ)
        {
            destroyChunk(chunkX, chunkZ);
            activeChunks.erase(std::remove(activeChunks.begin(), activeChunks.end(), chunk), activeChunks.end());
        }
    }
}

void World::createChunk(uint16_t x, uint16_t z)
{
    chunks[x][z] = new Chunk(glm::vec3(x * VoxelData::CHUNK_SIZE, 0, z * VoxelData::CHUNK_SIZE), &perlinNoise);

    Dog::Engine::activeScene->instantiate(chunks[x][z]);
}

void World::destroyChunk(uint16_t x, uint16_t z)
{
    Chunk *chunk = chunks[x][z];

    if (chunk != nullptr)
    {
        Dog::Engine::activeScene->destroy(chunk);
        // chunk->mesh.clear();
        chunks[x][z] = nullptr;
    }
}
