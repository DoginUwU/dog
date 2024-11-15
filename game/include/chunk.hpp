#pragma once
#include "fast_noise_lite.hpp"
#include "core/game_object.hpp"

class Chunk final : public GameObject {
public:
    void start() override {
        //shader = GameManager::assets_library->get_shader("Object");
        material = GameManager::assets_library->get_material("Terrain1");
        mesh = Engine::graphics_factory->create_mesh();

        GameObject::start();

        generate_mesh();
    }

    void update(const float delta_time) override {
        GameObject::update(delta_time);
    }

private:
    unsigned int vertex_index = 0;
    unsigned int grid_size_x = 100;
    unsigned int grid_size_z = 100;
    FastNoiseLite noise;

    void generate_mesh() {
        noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
        noise.SetFrequency(0.025f);
        noise.SetFractalType(FastNoiseLite::FractalType_FBm);
        noise.SetFractalOctaves(4);
        noise.SetFractalLacunarity(8);
        noise.SetFractalGain(0.13f);
        noise.SetFractalWeightedStrength(2);

        for (int z = 0; z < grid_size_z; z++) {
            unsigned int triangles = 0;
            bool initial_quad = true;

            for (int x = 0; x < grid_size_x; x++) {
                if (initial_quad) {
                    initial_quad = false;

                    add_vertex(static_cast<float>(x) + -.5f, static_cast<float>(z) + .5f);
                    add_vertex(static_cast<float>(x) + -.5f, static_cast<float>(z) + -.5f);

                    add_vertex(static_cast<float>(x) + .5f, static_cast<float>(z) + .5f);
                    add_vertex(static_cast<float>(x) + .5f, static_cast<float>(z) + -.5f);

                    triangles += 2;

                    continue;
                }

                add_vertex(static_cast<float>(x) + .5f, static_cast<float>(z) + .5f);
                add_vertex(static_cast<float>(x) + .5f, static_cast<float>(z) + -.5f);

                triangles += 2;
            }

            for (int i = 0; i < triangles / 2; ++i) {
                mesh->indices.push_back(vertex_index + 0);
                mesh->indices.push_back(vertex_index + 1);
                mesh->indices.push_back(vertex_index + 3);

                mesh->indices.push_back(vertex_index + 0);
                mesh->indices.push_back(vertex_index + 3);
                mesh->indices.push_back(vertex_index + 2);

                vertex_index += 2;
            }

            vertex_index += 2;
        }

        mesh->optimize();
        mesh->update();
    }

    void add_vertex(const float x, const float z) const {
        const float y = noise.GetNoise(x, z);

        mesh->vertices.push_back(x);
        mesh->vertices.push_back(y * 3);
        mesh->vertices.push_back(z);

        mesh->uvs.push_back(x);
        mesh->uvs.push_back(z);
    }
};
