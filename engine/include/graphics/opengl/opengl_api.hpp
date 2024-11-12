#pragma once
#include "graphics/renderer_api.hpp"

class OpenGLAPI final : public RendererAPI {
public:
    OpenGLAPI();

    void init() override;

    void clear() override;

    void draw() override;

    ~OpenGLAPI() override;
};
