#ifndef DOG_OBJECT_HPP
#define DOG_OBJECT_HPP
#include "component.hpp"
#include "gl/mesh.hpp"
#include "transform.hpp"

namespace Dog
{
    class Object : public Component
    {
    public:
        Transform transform;

        Object();
        ~Object();

        virtual void start() = 0;
        virtual void update(float deltaTime);

    protected:
        Mesh mesh;
    };
}
#endif