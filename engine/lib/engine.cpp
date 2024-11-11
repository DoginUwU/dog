#include <engine.hpp>

#include "graphics/graphics_factory.hpp"
#include "graphics/shaders.hpp"
#include "graphics/opengl/opengl_factory.hpp"

Engine::Engine() {
    const std::unique_ptr<GraphicsFactory> factory = std::make_unique<OpenGLFactory>();

    window = factory->create_window_api();
    window->create_window(800, 600, "Dog Engine");

    renderer = factory->create_renderer_api();
    renderer->init();

    game_manager = std::make_unique<GameManager>();

    // TODO: check if here it's better place to it
    Shaders::start();
}

void Engine::loop() const {
    while (!window->should_close()) {
        renderer->clear();
        window->update();
        game_manager->update();
        renderer->draw();
    }
}
