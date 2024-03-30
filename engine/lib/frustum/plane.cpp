#include "frustum/plane.hpp"

namespace Dog
{
    Plane::Plane(glm::vec4 quaternion)
    {
        this->quaternion = quaternion;
    }

    void Plane::normalize()
    {
        float length = glm::length(quaternion);

        quaternion /= length;
    }

    float Plane::distance(glm::vec3 point)
    {
        return glm::dot(glm::vec3(quaternion), point) + quaternion.w;
    }
}
