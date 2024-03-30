#include "camera.hpp"

class FlyCamera : public Dog::Camera
{
public:
    const float speed = 5.0f;
    const float sensitivity = 0.1f;

    FlyCamera();
    ~FlyCamera();

    void start();
    void update(float deltaTime);

private:
    float yaw = 0;
    float pitch = 0;
    float lastX = 0;
    float lastY = 0;

    void processInput(float deltaTime);
    void processMouse(float x, float y);
};
