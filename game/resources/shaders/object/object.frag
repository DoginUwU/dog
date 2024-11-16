#version 460 core

out vec4 frag_color;

in vec3 frag_position;
in vec3 frag_normal;
in vec4 vertex_color;
in vec2 texture_coord;

struct BaseLight {
    vec3 color;
    float ambient;
    float diffuse;
};

struct DirectionalLight {
    BaseLight base;
    vec3 direction;
};

struct Material {
    vec3 ambient;
    vec3 diffuse;
    vec3 specular;
    float shininess;
};

#define MAX_DIRECTIONAL_LIGHTS 4

uniform vec3 camera_position;
uniform sampler2D texture1;
uniform Material material;
uniform DirectionalLight directional_lights[MAX_DIRECTIONAL_LIGHTS];

vec4 get_directional_light(DirectionalLight directional_light, vec3 normal) {
    vec3 ambient_color = vec3(directional_light.base.color * directional_light.base.ambient);
    float diffuse_factor = dot(normal, -directional_light.direction);

    vec3 diffuse_color;

    if (diffuse_factor > 0.0) {
        diffuse_color = vec3(directional_light.base.color * directional_light.base.diffuse * diffuse_factor);
    } else {
        diffuse_color = vec3(0.0, 0.0, 0.0);
    }

    vec3 view_direction = normalize(camera_position - frag_position);
    vec3 reflection_direction = reflect(directional_light.direction, normal);
    float specular_factor = pow(max(dot(view_direction, reflection_direction), 0.0), material.shininess);
    vec3 specular = directional_light.base.color * specular_factor * material.specular;

    return vec4(ambient_color + diffuse_color + specular, 1.0);
}

void main() {
    vec4 texture_color = texture(texture1, texture_coord);

    vec4 lighinting_result = get_directional_light(directional_lights[0], frag_normal);

    frag_color = texture_color * lighinting_result;
}
