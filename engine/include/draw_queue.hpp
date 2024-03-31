#ifndef DOG_DRAW_QUEUE_HPP
#define DOG_DRAW_QUEUE_HPP
#include <mutex>
#include <queue>
#include <functional>

namespace Dog
{
    class DrawQueue
    {
    public:
        inline static DrawQueue *instance = nullptr;

        DrawQueue();

        void addTask(std::function<void()> task);
        void executeTasks();

    private:
        std::queue<std::function<void()>> tasks;
        std::mutex queueMutex;
    };
}

#endif
