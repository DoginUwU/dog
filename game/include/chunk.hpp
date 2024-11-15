#pragma once

#include "fast_noise_lite.hpp"
#include "core/game_object.hpp"

struct TerrainRandomizer {
    float frequency;
    int octaves;
    float lacunarity;
    float gain;
    float strength;
};

struct ObjectsRandomizer {
};

class Chunk final : public GameObject {
public:
    explicit Chunk(const Vector3F &position) {
        transform.set_position(position * Vector3F{grid_size_x, 0, grid_size_z});

        chunk_position_x = transform.position().x();
        chunk_position_z = transform.position().z();
    }

    void start() override {
        material = GameManager::assets_library->get_material("Terrain1");
        mesh = Engine::graphics_factory->create_mesh();

        GameObject::start();

        generate_mesh(PLAIN_DEFAULT);
    }

    void update(const float delta_time) override {
        GameObject::update(delta_time);
    }

private:
    const TerrainRandomizer PLAIN_DEFAULT = {
        .frequency = 0.025f,
        .octaves = 4,
        .lacunarity = 8,
        .gain = 0.13f,
        .strength = 2,
    };

    FastNoiseLite noise;

    unsigned int vertex_index = 0;
    unsigned int grid_size_x = 100;
    unsigned int grid_size_z = 100;
    float chunk_position_x = 0;
    float chunk_position_z = 0;
    float quad_scale = 1.0f;

    void generate_mesh(const TerrainRandomizer &randomizer) {
        noise.SetNoiseType(FastNoiseLite::NoiseType_OpenSimplex2);
        noise.SetFractalType(FastNoiseLite::FractalType_FBm);
        noise.SetFrequency(randomizer.frequency);
        noise.SetFractalOctaves(randomizer.octaves);
        noise.SetFractalLacunarity(randomizer.lacunarity);
        noise.SetFractalGain(randomizer.gain);
        noise.SetFractalWeightedStrength(randomizer.strength);

        for (int z = 0; z < grid_size_z; z++) {
            unsigned int triangles = 0;
            bool initial_quad = true;

            for (int x = 0; x < grid_size_x; x++) {
                if (initial_quad) {
                    initial_quad = false;

                    add_vertex(static_cast<float>(x) + -(quad_scale / 2), static_cast<float>(z) + (quad_scale / 2));
                    add_vertex(static_cast<float>(x) + -(quad_scale / 2), static_cast<float>(z) + -(quad_scale / 2));

                    add_vertex(static_cast<float>(x) + (quad_scale / 2), static_cast<float>(z) + (quad_scale / 2));
                    add_vertex(static_cast<float>(x) + (quad_scale / 2), static_cast<float>(z) + -(quad_scale / 2));

                    add_uv(static_cast<float>(x) + 0.0f, static_cast<float>(z) + 1.0f);
                    add_uv(static_cast<float>(x) + 0.0f, static_cast<float>(z) + 0.0f);
                    add_uv(static_cast<float>(x) + 1.0f, static_cast<float>(z) + 1.0f);
                    add_uv(static_cast<float>(x) + 1.0f, static_cast<float>(z) + 0.0f);

                    triangles += 2;

                    continue;
                }

                add_vertex(static_cast<float>(x) + (quad_scale / 2), static_cast<float>(z) + (quad_scale / 2));
                add_vertex(static_cast<float>(x) + (quad_scale / 2), static_cast<float>(z) + -(quad_scale / 2));
                add_uv(static_cast<float>(x) + 1.0f, static_cast<float>(z) + 1.0f);
                add_uv(static_cast<float>(x) + 1.0f, static_cast<float>(z) + 0.0f);

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
        const float y = noise.GetNoise(x + chunk_position_x, z + chunk_position_z);

        mesh->vertices.push_back(x);
        mesh->vertices.push_back(y * 3);
        mesh->vertices.push_back(z);
    }

    void add_uv(const float u, const float v) const {
        mesh->uvs.push_back(u);
        mesh->uvs.push_back(v);
    }
};
