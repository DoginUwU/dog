#include "draw_queue.hpp"

#include <iostream>

namespace Dog
{
    DrawQueue::DrawQueue()
    {
        if (DrawQueue::instance != nullptr)
        {
            std::cerr << "DrawQueue instance already exists" << std::endl;
            return;
        }

        DrawQueue::instance = this;
    }

    void DrawQueue::addTask(std::function<void()> task)
    {
        std::lock_guard<std::mutex> lock(queueMutex);

        tasks.push(task);
    }

    void DrawQueue::executeTasks()
    {
        std::lock_guard<std::mutex> lock(queueMutex);

        while (!tasks.empty())
        {
            tasks.front()();
            tasks.pop();
        }
    }
}
