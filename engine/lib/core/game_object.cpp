#include <core/game_object.hpp>

#include "utils/assert.hpp"

void GameObject::after_start() {
    Assert::check_nullptr(mesh, "GameObject without mesh called");

    mesh->update();
}


void GameObject::draw() const {
    Assert::check_nullptr(shader, "GameObject without shader called to draw");
    Assert::check_nullptr(mesh, "GameObject without mesh called to draw");

    shader->bind();
    mesh->bind();
    mesh->draw();
    mesh->unbind();
    shader->unbind();
}
