#pragma once

class Object {
public:
    virtual void awake() {
    };

    virtual void start() {
    };

    virtual void update(float delta_time) = 0;

    virtual ~Object() = default;
};
