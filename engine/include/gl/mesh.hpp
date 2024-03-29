#ifndef DOG_MESH_HPP
#define DOG_MESH_HPP
#include <stdint.h>
#include <vector>

namespace Dog
{
    struct Vertex
    {
        float position[3];
        uint_least8_t color[3];
    };

    class Mesh
    {
    public:
        std::vector<Vertex> vertices;
        std::vector<uint32_t> indices;

        Mesh();
        ~Mesh();

        void draw();
        void clear();
        void optimize();

    protected:
        uint32_t vao;
        uint32_t vbo;
        uint32_t ebo;
    };
}
#endif
