#ifndef COMPONENT_HPP
#define COMPONENT_HPP

namespace Dog
{
    class Component
    {
    public:
        Component();
        ~Component();

        virtual void start() = 0;
        virtual void update(float deltaTime) = 0;
    };
}
#endif
