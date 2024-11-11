#pragma once

class Object {
public:
    virtual void start() = 0;

    virtual void update() = 0;

    virtual ~Object() = default;
};
