#include <engine.hpp>

#include "graphics/graphics_factory.hpp"
#include "graphics/opengl/opengl_factory.hpp"

Engine::Engine() {
    factory = std::make_unique<OpenGLFactory>();

    window = factory->create_window_api();
    window->create_window(800, 600, "Dog Engine");

    renderer = factory->create_renderer_api();
    renderer->init();

    shader_library = std::make_unique<ShaderLibrary>();

    game_manager = std::make_unique<GameManager>();
}

void Engine::loop() const {
    while (!window->should_close()) {
        renderer->clear();
        game_manager->update();
        renderer->draw();
        window->update();
    }
}
