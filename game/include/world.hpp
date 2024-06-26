#include "component.hpp"
#include "voxel.hpp"
#include "chunk.hpp"
#include "perlin_noise.hpp"
#include "camera.hpp"

#include <vector>
#include <mutex>
#include <thread>

class World : public Dog::Component
{
public:
    explicit World(Dog::Camera *camera);
    ~World();

    void start() override;
    void update(float deltaTime) override;
    void updateChunksAroundPlayer();

    void createChunk(uint16_t x, uint16_t z);
    void destroyChunk(uint16_t x, uint16_t z);

private:
    Chunk *chunks[VoxelData::WORLD_SIZE][VoxelData::WORLD_SIZE]{};
    const siv::PerlinNoise perlinNoise{std::random_device()()};
    Dog::Camera *camera;
    std::vector<Chunk *> activeChunks;

    std::mutex chunkMutex;
    std::thread chunkThread;
};
