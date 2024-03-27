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
    float yaw;
    float pitch;
    float lastX;
    float lastY;
    bool firstMouse;

    void processInput(float deltaTime);
    void processMouse(float x, float y);
};
