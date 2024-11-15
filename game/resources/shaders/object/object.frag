#version 460 core

out vec4 frag_color;

in vec3 frag_position;
in vec3 frag_normal;
in vec4 vertex_color;
in vec2 texture_coord;

struct BaseLight {
    vec3 color;
    float ambient_intensity;
    float diffuse_intensity;
};

struct DirectionalLight {
    BaseLight base;
    vec3 direction;
};

#define MAX_DIRECTIONAL_LIGHTS 4

uniform sampler2D texture1;
uniform DirectionalLight directional_lights[MAX_DIRECTIONAL_LIGHTS];

vec4 get_directional_light(vec4 current_color, DirectionalLight directional_light, vec3 normal) {
    vec4 ambient_color = vec4(directional_light.base.color * directional_light.base.ambient_intensity, 1.0);
    float diffuse_factor = dot(normal, -directional_light.direction);

    vec4 diffuse_color;

    if (diffuse_factor > 0.0) {
        diffuse_color = vec4(directional_light.base.color * directional_light.base.diffuse_intensity * diffuse_factor, 1.0f);
    } else {
        diffuse_color = vec4(0.0, 0.0, 0.0, 0.0);
    }

    return current_color * (ambient_color + diffuse_color);
}

void main() {
    vec4 texture_color = texture(texture1, texture_coord);

    frag_color = get_directional_light(texture_color, directional_lights[0], frag_normal);
}
