#include "object.hpp"
#include "perlin_noise.hpp"
#include "voxel.hpp"

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

    void start() override;
    void update(float deltaTime) override;

private:
    const siv::PerlinNoise *perlinNoise;
    uint32_t vertexIndex = 0;
    std::map<RoundedCoords, double> blockHeights;

    void createMesh();
    void createBlock(double x, double y, double z);

    bool isFaceVisible(double x, double y, double z, Direction direction);

    double getBlockHeight(double x, double z);
};
