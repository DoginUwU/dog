#include <engine.hpp>

#include "graphics/graphics_factory.hpp"
#include "graphics/opengl/opengl_factory.hpp"

Engine::Engine() {
    const std::unique_ptr<GraphicsFactory> factory = std::make_unique<OpenGLFactory>();

    window = factory->create_window_api();
    window->create_window(800, 600, "My engine");

    renderer = factory->create_renderer_api();
    renderer->init();
}

void Engine::loop() const {
    while (!window->should_close()) {
        renderer->clear();
        window->update();
        renderer->draw();
    }
}
