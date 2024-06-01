#include "gl/input.hpp"

namespace Dog
{
    void Input::init(GLFWwindow *window)
    {
        glfwSetKeyCallback(window, keyCallback);
        glfwSetCursorPosCallback(window, mouseCallback);
    }

    void Input::keyCallback(GLFWwindow *window, const int key, int scancode, const int action, int mode)
    {
        if (action == GLFW_PRESS)
        {
            keys[key] = true;
        }
        else if (action == GLFW_RELEASE)
        {
            keys[key] = false;
            keysProcessed[key] = false;
        }
    }

    bool Input::isKeyPressed(int key)
    {
        if (keys[key] && !keysProcessed[key])
        {
            keysProcessed[key] = true;
            return true;
        }

        return false;
    }

    bool Input::isKeyDown(const int key)
    {
        return keys[key];
    }

    void Input::mouseCallback(GLFWwindow *window, const double xpos, const double ypos)
    {
        mouseX = xpos;
        mouseY = ypos;
    }
}
