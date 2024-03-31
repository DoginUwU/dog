#include "gl/mesh_queue.hpp"

#include <iostream>

namespace Dog
{
    MeshQueue::MeshQueue()
    {
        MeshQueue::instance = this;
    }

    void MeshQueue::addMeshToQueue(Mesh *mesh)
    {
        std::lock_guard<std::mutex> lock(queueMutex);

        meshQueue.push_back(mesh);
        mesh->init();
    }

    void MeshQueue::drawQueue()
    {
        std::lock_guard<std::mutex> lock(queueMutex);

        for (Mesh *mesh : meshQueue)
        {
            mesh->draw();
        }
    }
}
