#include <graphics/mesh.hpp>

#include "math/vector_3f.hpp"

void Mesh::optimize() {
    vertices.shrink_to_fit();
    indices.shrink_to_fit();
    uvs.shrink_to_fit();
    normals.shrink_to_fit();
}

void Mesh::calculate_normals() {
    normals.resize(vertices.size(), 0.0f);

    // ↑Nf = (↑B - ↑A) × (↑C - ↑A)

    for (size_t i = 0; i < indices.size(); i += 3) {
        const unsigned int idx0 = indices[i];
        const unsigned int idx1 = indices[i + 1];
        const unsigned int idx2 = indices[i + 2];

        Vector3F v0{
            vertices[idx0 * 3 + 0],
            vertices[idx0 * 3 + 1],
            vertices[idx0 * 3 + 2],
        };
        Vector3F v1{
            vertices[idx1 * 3 + 0],
            vertices[idx1 * 3 + 1],
            vertices[idx1 * 3 + 2],
        };
        Vector3F v2{
            vertices[idx2 * 3 + 0],
            vertices[idx2 * 3 + 1],
            vertices[idx2 * 3 + 2],
        };

        Vector3F edge1 = v1 - v0;
        Vector3F edge2 = v2 - v0;
        Vector3F face_normal = Vector3F::normalize(Vector3F::cross(edge1, edge2));

        normals[idx0 * 3 + 0] += face_normal.x();
        normals[idx0 * 3 + 1] += face_normal.y();
        normals[idx0 * 3 + 2] += face_normal.z();

        normals[idx1 * 3 + 0] += face_normal.x();
        normals[idx1 * 3 + 1] += face_normal.y();
        normals[idx1 * 3 + 2] += face_normal.z();

        normals[idx2 * 3 + 0] += face_normal.x();
        normals[idx2 * 3 + 1] += face_normal.y();
        normals[idx2 * 3 + 2] += face_normal.z();
    }

    for (int i = 0; i < normals.size(); i += 3) {
        Vector3F normal{
            normals[i + 0], normals[i + 1], normals[i + 2]
        };
        normal = Vector3F::normalize(normal);

        normals[i + 0] = normal.x();
        normals[i + 1] = normal.y();
        normals[i + 2] = normal.z();
    }
}
