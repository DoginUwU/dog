#include <graphics/opengl/opengl_mesh.hpp>
#include <glad/gl.h>

OpenGLMesh::OpenGLMesh() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
}

void OpenGLMesh::update() {
    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);

    // TODO: handle colours?

    unbind();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}


void OpenGLMesh::bind() {
    glBindVertexArray(vao);
}

void OpenGLMesh::draw() {
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
}

void OpenGLMesh::unbind() {
    glBindVertexArray(0);
}

OpenGLMesh::~OpenGLMesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteVertexArrays(1, &vao);
}
