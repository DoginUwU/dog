#include <graphics/mesh.hpp>

Mesh::Mesh() {
}

Mesh::~Mesh() {
}

void Mesh::optimize() {
    vertices.shrink_to_fit();
    indices.shrink_to_fit();
}
