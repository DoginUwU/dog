#include <glad/gl.h>
#include <GLFW/glfw3.h>

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

        bool shouldClose() const;

    private:
        GLFWwindow *window;
        bool wireframeMode = false;
    };
}
