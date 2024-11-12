#include <engine.hpp>

#include "graphics/graphics_factory.hpp"
#include "graphics/opengl/opengl_factory.hpp"

Engine::Engine() {
    graphics_factory = std::make_unique<OpenGLFactory>();

    window = graphics_factory->create_window_api();
    window->create_window(800, 600, "Dog Engine");

    renderer = graphics_factory->create_renderer_api();
    renderer->init();

    game_manager = std::make_unique<GameManager>();
}

void Engine::loop() {
    while (!window->should_close()) {
        renderer->clear();
        game_manager->update();
        renderer->draw();
        window->update();
    }
}
