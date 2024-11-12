#pragma once

class Object {
public:
    virtual void awake() {
    };

    virtual void start() {
    };

    virtual void update() = 0;

    virtual ~Object() = default;
};
