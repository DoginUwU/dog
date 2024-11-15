#version 460 core

layout (location = 0) in vec3 pos;
layout (location = 1) in vec3 color;
layout (location = 2) in vec2 m_texture_coord;

out vec4 vertex_color;
out vec2 texture_coord;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(pos, 1.0);
    vertex_color = vec4(1.0, 1.0, 1.0, 0.0);
    texture_coord = vec2(m_texture_coord.x, m_texture_coord.y);
}
