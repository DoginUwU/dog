#include <glm/glm.hpp>

namespace Dog
{
    class Plane
    {
    public:
        glm::vec4 quaternion;

        Plane(glm::vec4 quaternion);

        void normalize();
        float distance(glm::vec3 point);
    };
}
