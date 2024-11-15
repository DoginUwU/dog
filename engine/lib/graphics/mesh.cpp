#include <graphics/mesh.hpp>

void Mesh::optimize() {
    vertices.shrink_to_fit();
    indices.shrink_to_fit();
    uvs.shrink_to_fit();
    normals.shrink_to_fit();
}
