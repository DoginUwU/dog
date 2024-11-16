#include <graphics/opengl/opengl_mesh.hpp>
#include <glad/gl.h>

OpenGLMesh::OpenGLMesh() {
    glGenVertexArrays(1, &vao);
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glGenBuffers(1, &uv_vbo);
    glGenBuffers(1, &normal_vbo);
    glGenBuffers(1, &color_vbo);
}

void OpenGLMesh::update() {
    glBindVertexArray(vao);

#pragma region vbo
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(vertices.size() * sizeof(float)), vertices.data(),
                 GL_STATIC_DRAW);
#pragma endregion

#pragma region indices
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, static_cast<GLsizeiptr>(indices.size() * sizeof(unsigned int)),
                 indices.data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(0);
#pragma endregion

#pragma region colors
    glBindBuffer(GL_ARRAY_BUFFER, color_vbo);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(colors.size() * sizeof(float)), colors.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(1, 3, GL_FLOAT, GL_TRUE, 3 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(1);
#pragma endregion

#pragma region uvs
    glBindBuffer(GL_ARRAY_BUFFER, uv_vbo);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(uvs.size() * sizeof(float)), uvs.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(2);
#pragma endregion

#pragma region normals
    glBindBuffer(GL_ARRAY_BUFFER, normal_vbo);
    glBufferData(GL_ARRAY_BUFFER, static_cast<GLsizeiptr>(normals.size() * sizeof(float)), normals.data(),
                 GL_STATIC_DRAW);

    glVertexAttribPointer(3, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), static_cast<void *>(nullptr));
    glEnableVertexAttribArray(3);
#pragma endregion

    unbind();
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);

    updated_first_time = true;
}

void OpenGLMesh::bind() {
    glBindVertexArray(vao);
}

void OpenGLMesh::draw() {
    if (!updated_first_time) {
        return;
    }

    glDrawElements(GL_TRIANGLES, static_cast<GLsizei>(indices.size()), GL_UNSIGNED_INT, nullptr);
}

void OpenGLMesh::unbind() {
    glBindVertexArray(0);
}

OpenGLMesh::~OpenGLMesh() {
    glDeleteBuffers(1, &vbo);
    glDeleteBuffers(1, &ebo);
    glDeleteBuffers(1, &uv_vbo);
    glDeleteBuffers(1, &normal_vbo);
    glDeleteBuffers(1, &color_vbo);
    glDeleteVertexArrays(1, &vao);
}
