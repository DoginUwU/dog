#include "frustum/plane.hpp"

namespace Dog
{
    Plane::Plane(const glm::vec4 quaternion)
    {
        this->quaternion = quaternion;
    }

    void Plane::normalize()
    {
        const float length = glm::length(quaternion);

        quaternion /= length;
    }

    float Plane::distance(const glm::vec3 point) const
    {
        return glm::dot(glm::vec3(quaternion), point) + quaternion.w;
    }
}
