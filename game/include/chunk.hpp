#include "object.hpp"
#include "perlin_noise.hpp"
#include "voxel.hpp"
#include "frustum/aabb.hpp"

#include <map>

struct RoundedCoords
{
    int x;
    int z;

    bool operator<(const RoundedCoords &other) const
    {
        return x < other.x || (x == other.x && z < other.z);
    }
};

class Chunk : public Dog::Object
{
public:
    Chunk(glm::vec3 position, const siv::PerlinNoise *perlinNoise);
    ~Chunk();

    void start();
    void update(float deltaTime);

private:
    const siv::PerlinNoise *perlinNoise;
    uint32_t vertexIndex = 0;
    std::map<RoundedCoords, float> blockHeights;

    void createMesh();
    void createBlock(float x, float y, float z);

    bool isFaceVisible(float x, float y, float z, Direction direction);

    float getBlockHeight(float x, float z);
};
