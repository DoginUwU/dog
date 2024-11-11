#version 460 core

out vec4 vertex_color;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = vec4(1.0, 1.0, 1.0, 1.0);
    vertex_color = vec4(1.0, 1.0, 1.0, 1.0);
}