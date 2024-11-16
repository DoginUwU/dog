#version 460 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 m_texture_coord;
layout (location = 3) in vec3 m_normal;

out vec3 frag_position;
out vec3 frag_normal;
out vec4 vertex_color;
out vec2 texture_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

uniform bool has_colors;

void main() {
    frag_position = vec3(model * vec4(pos, 1.0f));
    frag_normal = mat3(transpose(inverse(model))) * m_normal;

    if (has_colors) {
        vertex_color = vec4(color, 0.0);
    } else {
        vertex_color = vec4(1.0, 1.0, 1.0, 0.0);
    }

    texture_coord = vec2(m_texture_coord.x, m_texture_coord.y);

    gl_Position = projection * view * vec4(frag_position, 1.0);
}
