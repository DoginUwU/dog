#include "plane.hpp"
#include "aabb.hpp"

namespace Dog
{
    class Frustum
    {
    public:
        Plane *planes[6];

        explicit Frustum(glm::mat4 viewProjection);
        ~Frustum();

        void frustrate(glm::mat4 viewProjection);
        bool pointInFrustum(glm::vec3 point, float radius) const;
        bool aabbInFrustum(const AABB *aabb) const;
    };
}
