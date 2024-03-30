#include "frustum/aabb.hpp"

namespace Dog
{
    AABB::AABB(glm::vec3 min, glm::vec3 max)
    {
        this->min = min;
        this->max = max;

        getCorners();
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

    void AABB::getCorners()
    {
        glm::vec3 *corners = new glm::vec3[8];

        corners[0] = glm::vec3(min.x, min.y, min.z);
        corners[1] = glm::vec3(max.x, min.y, min.z);
        corners[2] = glm::vec3(max.x, max.y, min.z);
        corners[3] = glm::vec3(min.x, max.y, min.z);
        corners[4] = glm::vec3(min.x, min.y, max.z);
        corners[5] = glm::vec3(max.x, min.y, max.z);
        corners[6] = glm::vec3(max.x, max.y, max.z);
        corners[7] = glm::vec3(min.x, max.y, max.z);

        this->corners = corners;
    }
}
