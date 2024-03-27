#ifndef INPUT_HPP
#define INPUT_HPP
#include <GLFW/glfw3.h>

namespace Dog
{
    class Input
    {
    public:
        inline static bool keys[1024] = {false};
        inline static bool keysProcessed[1024] = {false};
        inline static float mouseX = 0.0f;
        inline static float mouseY = 0.0f;

        static void init(GLFWwindow *window);
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode);
        static bool isKeyPressed(int key);
        static bool isKeyDown(int key);

        static void mouseCallback(GLFWwindow *window, double xpos, double ypos);
    };
}
#endif
