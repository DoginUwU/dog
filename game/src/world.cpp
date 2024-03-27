#include "world.hpp"

#include "engine.hpp"

World::World(Dog::Camera *camera)
{
    this->camera = camera;
    camera->position = glm::vec3(VoxelData::WORLD_SIZE / 2, 1.0f, VoxelData::WORLD_SIZE / 2);

    // for (int x = 0; x < VoxelData::WORLD_SIZE; x++)
    // {
    //     for (int z = 0; z < VoxelData::WORLD_SIZE; z++)
    //     {
    //         chunks[x][z] = new Chunk(glm::vec3(x * VoxelData::CHUNK_SIZE, 0, z * VoxelData::CHUNK_SIZE), &perlinNoise);

    //         Dog::Engine::activeScene->instantiate(chunks[x][z]);
    //     }
    // }
}

World::~World()
{
}

void World::start()
{
}

void World::update(float deltaTime)
{
    updateChunkVisibility();
}

void World::updateChunkVisibility()
{
    glm::vec3 cameraPosition = camera->position / glm::vec3(VoxelData::CHUNK_SIZE, VoxelData::CHUNK_SIZE_Y, VoxelData::CHUNK_SIZE);

    for (uint16_t x = cameraPosition.x - VoxelData::RENDER_DISTANCE; x < cameraPosition.x + VoxelData::RENDER_DISTANCE; x++)
    {
        for (uint16_t z = cameraPosition.z - VoxelData::RENDER_DISTANCE; z < cameraPosition.z + VoxelData::RENDER_DISTANCE; z++)
        {
            Chunk *chunk = chunks[x][z];

            if (chunk == nullptr)
            {
                createChunk(x, z);

                continue;
            }
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
        chunk->mesh.clear();
        chunks[x][z] = nullptr;
    }
}
