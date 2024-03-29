#include "camera.hpp"
#include "shaders.hpp"

#include <glm/ext/matrix_clip_space.hpp>
#include <glm/ext/matrix_transform.hpp>

namespace Dog
{
    Camera::Camera()
    {
        view = glm::mat4(1.0f);
        projection = glm::mat4(1.0f);
        position = glm::vec3(0.0f, 0.0f, 0.0f);
    }

    Camera::~Camera() {}

    void Camera::start()
    {
        aspectRatio = 800.0f / 600.0f;
        fov = 45.0f;
        near = 0.1f;
        far = 100.0f;

        projection = glm::perspective(glm::radians(fov), aspectRatio, near, far);
    }

    void Camera::update(float deltaTime)
    {
        view = glm::lookAt(position, position + front, up);

        Shaders::objectShader->setMat4(Shaders::objectShader->viewLoc, view);
        Shaders::objectShader->setMat4(Shaders::objectShader->projectionLoc, projection);
    }
}
