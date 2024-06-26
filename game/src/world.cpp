#include "world.hpp"
#include "engine.hpp"

#include <iostream>

World::World(Dog::Camera *camera)
{
    this->camera = camera;

    // createChunk(0, 0);
    // createChunk(1, 0);
    // createChunk(0, 1);
    // createChunk(1, 1);
    // updateChunksAroundPlayer();
    chunkThread = std::thread(&World::updateChunksAroundPlayer, this);
}

World::~World()
{
    chunkThread.join();
}

void World::start()
{
}

void World::update(float deltaTime)
{
    // chunkThread = std::thread(&World::updateChunksAroundPlayer, this);
}

void World::updateChunksAroundPlayer()
{
    while (true)
    {
        const glm::vec3 playerPosition = camera->position;

        const uint16_t playerChunkX = playerPosition.x / VoxelData::CHUNK_SIZE;
        const uint16_t playerChunkZ = playerPosition.z / VoxelData::CHUNK_SIZE;

        const uint16_t playerMinChunkX = std::max(0, (int)playerChunkX - VoxelData::RENDER_DISTANCE);
        const uint16_t playerMinChunkZ = std::max(0, (int)playerChunkZ - VoxelData::RENDER_DISTANCE);
        const uint16_t playerMaxChunkX = playerChunkX + VoxelData::RENDER_DISTANCE;
        const uint16_t playerMaxChunkZ = playerChunkZ + VoxelData::RENDER_DISTANCE;

        for (uint16_t x = playerMinChunkX; x < playerMaxChunkX; x++)
        {
            for (uint16_t z = playerMinChunkZ; z < playerMaxChunkZ; z++)
            {
                if (chunks[x][z] == nullptr)
                {
                    createChunk(x, z);
                }
            }
        }

        for (auto chunk : activeChunks)
        {
            if (chunk == nullptr)
            {
                continue;
            }

            const uint16_t chunkX = chunk->transform.getPosition().x / VoxelData::CHUNK_SIZE;
            const uint16_t chunkZ = chunk->transform.getPosition().z / VoxelData::CHUNK_SIZE;

            if (chunkX < playerMinChunkX || chunkX >= playerMaxChunkX || chunkZ < playerMinChunkZ || chunkZ >= playerMaxChunkZ)
            {
                destroyChunk(chunkX, chunkZ);
                activeChunks.erase(std::remove(activeChunks.begin(), activeChunks.end(), chunk), activeChunks.end());
            }
        }
    }
}

void World::createChunk(const uint16_t x, const uint16_t z)
{
    auto *chunk = new Chunk(glm::vec3(x * VoxelData::CHUNK_SIZE, 0, z * VoxelData::CHUNK_SIZE), &perlinNoise);
    std::cout << "Chunk: " << x << ", " << z << std::endl;

    chunkMutex.lock();
    chunks[x][z] = chunk;
    Dog::Engine::activeScene->instantiate(chunks[x][z]);
    activeChunks.push_back(chunks[x][z]);
    chunkMutex.unlock();
}

void World::destroyChunk(const uint16_t x, const uint16_t z)
{
    Chunk *chunk = chunks[x][z];

    if (chunk != nullptr)
    {
        Dog::Engine::activeScene->destroy(chunk);
        chunk->mesh.clear();
        chunks[x][z] = nullptr;
    }
}
