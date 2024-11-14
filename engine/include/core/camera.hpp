#pragma once
#include "object.hpp"
#include "transform.hpp"

class Camera : public Object {
public:
    void start() override;

    void update(float delta_time) override;

    ~Camera() override = default;

    Matrix4F view = Matrix4F(1.0f);
    // TODO: projection needs to be here?
    Matrix4F projection = Matrix4F(1.0f);

protected:
    Vector3F position = {.0f, .0f, 3.0f};
    Vector3F front = {.0f, .0f, -1.0f};
    Vector3F up = {.0f, 1.0f, .0f};
};
