#pragma once

class Texture {
public:
    virtual void update() = 0;

    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual void draw() = 0;

    virtual ~Texture() = default;
};
