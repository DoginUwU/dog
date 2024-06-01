#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <glm/glm.hpp>

namespace Dog
{
    class Transform
    {
    public:
        Transform();

        glm::mat4 matrix{};

        void setPosition(const glm::vec3 &position);
        glm::vec3 getPosition() const;
    };
}
#endif
