#include "object.hpp"
#include "perlin_noise.hpp"
#include "voxel.hpp"
#include "frustum/aabb.hpp"
#include "camera.hpp"

class Chunk : public Dog::Object
{
public:
    Chunk(glm::vec3 position, const siv::PerlinNoise *perlinNoise, Dog::Camera *camera);
    ~Chunk();

    void start();
    void update(float deltaTime);

private:
    uint32_t vertexIndex = 0;
    const siv::PerlinNoise *perlinNoise;
    Dog::AABB *aabb;
    Dog::Camera *camera;

    void createMesh();
    void createBlock(float x, float y, float z);

    bool isFaceVisible(float x, float y, float z, Direction direction);

    float getBlockHeight(float x, float z);
};
