#pragma once

class RendererAPI {
public:
    virtual void init() = 0;

    virtual void clear() = 0;

    virtual void draw() = 0;

    virtual ~RendererAPI() = default;
};
