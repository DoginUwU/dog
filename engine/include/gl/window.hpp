#include <glad/gl.h>
#include <GLFW/glfw3.h>

namespace Dog
{
    class Window
    {
    public:
        Window();
        ~Window();

        void update() const;
        void close() const;

        bool shouldClose() const;

    private:
        GLFWwindow *window;
    };
}
