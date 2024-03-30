#ifndef DOG_OBJECT_HPP
#define DOG_OBJECT_HPP
#include "component.hpp"
#include "gl/mesh.hpp"
#include "transform.hpp"
#include "frustum/aabb.hpp"
#include "camera.hpp"

namespace Dog
{
    class Object : public Component
    {
    public:
        Transform transform;
        Mesh mesh;

        Object();
        ~Object();

        virtual void start() = 0;
        virtual void update(float deltaTime);

        void setCamera(Camera *camera);
        void setFrustumMixMax(glm::vec3 min, glm::vec3 max);

    protected:
        Camera *camera;
        AABB aabb;
    };
}
#endif
