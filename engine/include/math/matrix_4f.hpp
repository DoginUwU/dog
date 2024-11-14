#pragma once
#include <glm/glm.hpp>
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/ext/matrix_transform.hpp"

#include "vector_3f.hpp"

class Matrix4F {
public:
    glm::mat4 data;

    Matrix4F() : data(0.0f) {
    }

    explicit Matrix4F(const float s) : data(s) {
    }

    void perspective(const float fov, const float aspect_ratio, const float near, const float far) {
        data = glm::perspective(glm::radians(fov), aspect_ratio, near, far);
    }

    void look_at(const Vector3F &eye, const Vector3F &center, const Vector3F &up) {
        data = glm::lookAt(eye.data, center.data, up.data);
    }

    void translate(const Vector3F &translation) {
        data = glm::translate(data, translation.data);
    }
};
