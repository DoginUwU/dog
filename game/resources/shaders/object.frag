#version 460 core

out vec4 frag_color;

in vec4 vertex_color;
in vec2 texture_coord;

uniform sampler2D texture1;

void main() {
    //frag_color = vertex_color;
    frag_color = texture(texture1, texture_coord);
}