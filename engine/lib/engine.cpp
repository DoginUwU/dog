#include "engine.hpp"
#include "shaders.hpp"

#include <GLFW/glfw3.h>
#include <stdexcept>

namespace Dog
{
    Engine::Engine()
    {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (!glfwInit())
        {
            throw std::runtime_error("Failed to initialize GLFW");
        }

        window = new Window();
        lastFrame = glfwGetTime();
        previousTime = lastFrame;
    }

    Engine::~Engine()
    {
        Shaders::cleanup();
        delete window;
        glfwTerminate();
    }

    void Engine::run()
    {
        Shaders::init();
        activeScene->start();
        mainLoop();
    }

    void Engine::stop() const
    {
        window->close();
    }

    void Engine::setActiveScene(Scene *scene)
    {
        activeScene = scene;
    }

    void Engine::mainLoop()
    {
        while (!window->shouldClose())
        {
            glClearColor(0.84f, 0.96f, 1.0f, 1.0f);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

            const float currentFrame = glfwGetTime();
            const float deltaTime = currentFrame - lastFrame;
            lastFrame = currentFrame;

            frameCount++;

            if (currentFrame - previousTime >= 1.0)
            {
                window->setTitle("Dog Engine - " + std::to_string(frameCount) + " FPS");
                frameCount = 0;
                previousTime = currentFrame;
            }

            activeScene->update(deltaTime);
            window->update();

            glfwPollEvents();
        }
    }
}
