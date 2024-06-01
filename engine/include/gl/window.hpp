#include "draw_queue.hpp"

#include <glad/gl.h>
#include <GLFW/glfw3.h>

#include <string>

namespace Dog
{
    class Window
    {
    public:
        Window();
        ~Window();

        void update();
        void close() const;

        void toggleWireframeMode();

        void setTitle(const std::string& title) const;

        bool shouldClose() const;

    private:
        GLFWwindow *window;
        DrawQueue *drawQueue;

        bool wireframeMode = false;
    };
}
