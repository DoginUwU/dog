#include "fly-camera.hpp"

#include "gl/input.hpp"
#include <iostream>

using namespace Dog;

FlyCamera::FlyCamera()
= default;

FlyCamera::~FlyCamera()
= default;

void FlyCamera::start()
{
    Camera::start();
}

void FlyCamera::update(const float deltaTime)
{
    Camera::update(deltaTime);

    processInput(deltaTime);
    processMouse(Input::mouseX, Input::mouseY);
}

void FlyCamera::processInput(const float deltaTime)
{
    const float velocity = speed * deltaTime;

    if (Input::isKeyDown(GLFW_KEY_W))
    {
        position += front * velocity;
    }

    if (Input::isKeyDown(GLFW_KEY_S))
    {
        position -= front * velocity;
    }

    if (Input::isKeyDown(GLFW_KEY_A))
    {
        position -= glm::normalize(glm::cross(front, up)) * velocity;
    }

    if (Input::isKeyDown(GLFW_KEY_D))
    {
        position += glm::normalize(glm::cross(front, up)) * velocity;
    }
}

void FlyCamera::processMouse(const float x, const float y)
{
    float xOffset = x - lastX;
    float yOffset = lastY - y;

    lastX = x;
    lastY = y;

    xOffset *= sensitivity;
    yOffset *= sensitivity;

    yaw += xOffset;
    pitch += yOffset;

    if (pitch > 89.0f)
    {
        pitch = 89.0f;
    }

    if (pitch < -89.0f)
    {
        pitch = -89.0f;
    }

    glm::vec3 direction;
    direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
    direction.y = sin(glm::radians(pitch));
    direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
    front = glm::normalize(direction);
}
