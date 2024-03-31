#include "gl/mesh.hpp"
#include "shaders.hpp"

#include <glad/gl.h>
#include <cstddef>
#include <meshoptimizer.h>
#include <iostream>

namespace Dog
{
    Mesh::Mesh()
    {
    }

    Mesh::~Mesh()
    {
        glDeleteBuffers(1, &vbo);
        glDeleteBuffers(1, &ebo);
        glDeleteVertexArrays(1, &vao);
    }

    void Mesh::init()
    {
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        glGenBuffers(1, &vbo);
        glBindBuffer(GL_ARRAY_BUFFER, vbo);

        glGenBuffers(1, &ebo);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)offsetof(Vertex, position));
        glEnableVertexAttribArray(0);

        glVertexAttribPointer(1, 3, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void *)offsetof(Vertex, color));
        glEnableVertexAttribArray(1);
    }

    void Mesh::draw()
    {
        if (!isActive)
        {
            return;
        }

        Shaders::objectShader->setMat4(Shaders::objectShader->modelLoc, transform->matrix);
        Shaders::objectShader->use();

        glBindBuffer(GL_ARRAY_BUFFER, vbo);
        glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), GL_STATIC_DRAW);

        glBindVertexArray(vao);
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    }

    void Mesh::clear()
    {
        vertices.clear();
        indices.clear();

        vertices.shrink_to_fit();
        indices.shrink_to_fit();
    }

    void Mesh::optimize()
    {
        // std::vector<uint32_t> remap(vertices.size());

        // size_t vertexCount = meshopt_generateVertexRemap(remap.data(), indices.data(), indices.size(), vertices.data(), vertices.size(), sizeof(Vertex));

        // std::vector<Vertex> vertices_copy(vertices.size());
        // std::vector<uint32_t> indices_copy(indices.size());

        // meshopt_remapVertexBuffer(vertices_copy.data(), vertices.data(), vertices.size(), sizeof(Vertex), remap.data());
        // meshopt_remapIndexBuffer(indices_copy.data(), indices.data(), indices.size(), remap.data());

        // meshopt_optimizeOverdraw(indices_copy.data(), indices_copy.data(), indices.size(), (float *)&(vertices_copy[0].position[0]), vertices_copy.size(), sizeof(Vertex::position), 1.05f);

        // meshopt_optimizeVertexFetch(vertices_copy.data(), indices_copy.data(), indices_copy.size(), vertices_copy.data(), vertices_copy.size(), sizeof(Vertex));

        // meshopt_optimizeVertexCache(indices_copy.data(), indices_copy.data(), indices.size(), vertices.size());

        // vertices = vertices_copy;
        // indices = indices_copy;

        vertices.shrink_to_fit();
        indices.shrink_to_fit();
    }
}
