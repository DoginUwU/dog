#ifndef CAMERA_HPP
#define CAMERA_HPP
#include "component.hpp"
#include "transform.hpp"
#include "frustum/frustum.hpp"

#include <glm/glm.hpp>

namespace Dog
{
    class Camera : public Component
    {
    public:
        glm::mat4 view{};
        glm::mat4 projection{};
        glm::vec3 position{};

        float aspectRatio{};
        float fov{};
        float near{};
        float far{};

        Frustum *frustum;

        Camera();
        ~Camera();

        void start() override;
        void update(float deltaTime) override;

    protected:
        glm::vec3 front = glm::vec3(0.0f, 0.0f, -1.0f);
        glm::vec3 up = glm::vec3(0.0f, 1.0f, 0.0f);
        glm::vec3 right = glm::vec3(1.0f, 0.0f, 0.0f);
    };
}
#endif
