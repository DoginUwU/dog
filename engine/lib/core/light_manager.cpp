#include "core/light_manager.hpp"

#include "utils/assert.hpp"

void LightManager::upload_lighting_data(const std::shared_ptr<Shader> &shader, const std::unique_ptr<Scene> &scene) {
    Assert::check_nullptr(shader, "UploadLightingData without shader called");
    Assert::check_nullptr(scene, "UploadLightingData without scene called");

    static std::unordered_map<std::shared_ptr<Shader>, bool> shader_cache;
    if (shader_cache[shader]) {
        return;
    }

    shader_cache[shader] = true;

    for (int i = 0; i < scene->directional_lights.size(); ++i) {
        const auto &light = scene->directional_lights[i];

        shader->set_uniform("directional_lights[" + std::to_string(i) + "].base.color", light->base.color);
        shader->set_uniform("directional_lights[" + std::to_string(i) + "].base.ambient_intensity",
                            light->base.ambient_intensity);
        shader->set_uniform("directional_lights[" + std::to_string(i) + "].base.diffuse_intensity",
                            light->base.diffuse_intensity);

        shader->set_uniform("directional_lights[" + std::to_string(i) + "].direction", light->direction);
    }
}
