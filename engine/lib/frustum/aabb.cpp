#include "frustum/aabb.hpp"

namespace Dog
{
    AABB::AABB()
    = default;

    AABB::~AABB()
    = default;

    void AABB::setMinMax(const glm::vec3 min, const glm::vec3 max)
    {
        this->min = min;
        this->max = max;
    }

    bool AABB::intersects(const AABB &other) const
    {
        return min.x <= other.max.x && max.x >= other.min.x &&
               min.y <= other.max.y && max.y >= other.min.y &&
               min.z <= other.max.z && max.z >= other.min.z;
    }

    bool AABB::contains(const glm::vec3 &point) const
    {
        return point.x >= min.x && point.x <= max.x &&
               point.y >= min.y && point.y <= max.y &&
               point.z >= min.z && point.z <= max.z;
    }
}
