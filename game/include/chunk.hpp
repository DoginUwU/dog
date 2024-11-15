#pragma once
#include "core/game_object.hpp"
#include "core/logger.hpp"

class Chunk final : public GameObject {
public:
    void start() override {
        shader = GameManager::shader_library->get("Object");
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

    void generate_mesh() {
        for (int z = 0; z < grid_size_z; z++) {
            unsigned int triangles = 0;
            bool initial_quad = true;

            for (int x = 0; x < grid_size_x; x++) {
                if (initial_quad) {
                    initial_quad = false;

                    add_vertex(mesh->vertices, x + -.5f, 0, z + .5f);
                    add_vertex(mesh->vertices, x + -.5f, 0, z + -.5f);

                    add_vertex(mesh->vertices, x + .5f, 0, z + .5f);
                    add_vertex(mesh->vertices, x + .5f, 0, z + -.5f);

                    triangles += 2;

                    continue;
                }

                add_vertex(mesh->vertices, x + .5f, 0, z + .5f);
                add_vertex(mesh->vertices, x + .5f, 0, z + -.5f);

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

        //create_mesh_row(0);
        //create_mesh_row(2);

        if (false) {
            add_vertex(mesh->vertices, -1, 0, 1); // 0
            add_vertex(mesh->vertices, -1, 0, -1); // 1
            add_vertex(mesh->vertices, 1, 0, 1); // 2
            add_vertex(mesh->vertices, 1, 0, -1); // 3

            add_vertex(mesh->vertices, 3, 0, 1); // 4
            add_vertex(mesh->vertices, 3, 0, -1); // 5

            add_vertex(mesh->vertices, 5, 0, 1); // 6
            add_vertex(mesh->vertices, 5, 0, -1); // 7

            add_vertex(mesh->vertices, 7, 0, 1); // 8
            add_vertex(mesh->vertices, 7, 0, -1); // 9
        }

        if (false) {
            mesh->indices.push_back(0);
            mesh->indices.push_back(1);
            mesh->indices.push_back(3);

            mesh->indices.push_back(0);
            mesh->indices.push_back(3);
            mesh->indices.push_back(2);

            mesh->indices.push_back(2);
            mesh->indices.push_back(3);
            mesh->indices.push_back(5);

            mesh->indices.push_back(2);
            mesh->indices.push_back(5);
            mesh->indices.push_back(4);

            mesh->indices.push_back(4);
            mesh->indices.push_back(5);
            mesh->indices.push_back(7);

            mesh->indices.push_back(4);
            mesh->indices.push_back(7);
            mesh->indices.push_back(6);

            mesh->indices.push_back(6);
            mesh->indices.push_back(7);
            mesh->indices.push_back(9);

            mesh->indices.push_back(6);
            mesh->indices.push_back(9);
            mesh->indices.push_back(8);
        }

        mesh->optimize();
        mesh->update();
    }


    void create_mesh_row(const int z) {
        unsigned int count = 2;
        unsigned int triangles = 0;
        bool initial_quad = true;

        for (int x = 0; x < 10; x++) {
            if (initial_quad) {
                initial_quad = false;

                add_vertex(mesh->vertices, x + -1, 0, z + 1);
                add_vertex(mesh->vertices, x + -1, 0, z + -1);

                add_vertex(mesh->vertices, x + 1, 0, z + 1);
                add_vertex(mesh->vertices, x + 1, 0, z + -1);

                triangles += 2;

                continue;
            }

            add_vertex(mesh->vertices, x + count, 0, z + 1);
            add_vertex(mesh->vertices, x + count, 0, z + -1);

            triangles += 2;
            count++;
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

        Logger::info("Total triangles: %d", triangles);
    }

    static void add_vertex(std::vector<float> &vertices, const float x, const float y, const float z) {
        vertices.push_back(x);
        vertices.push_back(y);
        vertices.push_back(z);
    }
};
