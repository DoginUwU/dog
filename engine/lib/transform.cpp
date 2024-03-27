#include "transform.hpp"

#include <glm/ext/matrix_transform.hpp>

namespace Dog
{
    Transform::Transform()
    {
        matrix = glm::mat4(1.0f);
    }

    void Transform::setPosition(const glm::vec3 &position)
    {
        matrix = glm::translate(matrix, position);
    }

    glm::vec3 Transform::getPosition() const
    {
        return matrix[3];
    }
}