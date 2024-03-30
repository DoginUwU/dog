#ifndef DOG_AABB_HPP
#define DOG_AABB_HPP
#include <glm/glm.hpp>

namespace Dog
{
    class AABB
    {
    public:
        glm::vec3 min;
        glm::vec3 max;
        glm::vec3 *corners;

        AABB(glm::vec3 min, glm::vec3 max);

        bool intersects(const AABB &other) const;
        bool contains(const glm::vec3 &point) const;

    private:
        void getCorners();
    };
}
#endif