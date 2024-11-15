#pragma once

class Texture {
public:
    virtual void bind() = 0;

    virtual void unbind() = 0;

    virtual ~Texture() = default;
};
