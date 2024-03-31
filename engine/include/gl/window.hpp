#include <glad/gl.h>
#include <GLFW/glfw3.h>
#include <gl/mesh_queue.hpp>

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

        void setTitle(std::string title) const;

        bool shouldClose() const;

    private:
        GLFWwindow *window;
        MeshQueue *meshQueue;

        bool wireframeMode = false;
    };
}
