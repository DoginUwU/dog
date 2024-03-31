#define GLFW_INCLUDE_NONE

#include "gl/window.hpp"
#include "scene.hpp"

namespace Dog
{
    class Engine
    {
    public:
        inline static Scene *activeScene = nullptr;

        Engine();
        ~Engine();

        void run();
        void stop();
        void setActiveScene(Scene *scene);

    private:
        Window *window;

        double previousTime;
        float lastFrame;
        int frameCount;

        void mainLoop();
    };
}
