#ifndef DOG_MESH_QUEUE_HPP
#define DOG_MESH_QUEUE_HPP
#include "mesh.hpp"

#include <vector>
#include <mutex>

namespace Dog
{
    class MeshQueue
    {
        std::vector<Mesh *> meshQueue;
        std::mutex queueMutex;

    public:
        inline static MeshQueue *instance = nullptr;

        MeshQueue();

        void addMeshToQueue(Mesh *mesh);
        void drawQueue();
    };
}

#endif
