#pragma once

#include <string>

#include "tiny_obj_loader.hpp"
#include "core/logger.hpp"
#include "graphics/mesh.hpp"

class ObjectReader final {
public:
    static void read_obj(const std::unique_ptr<Mesh> &mesh, const std::string &path) {
        tinyobj::ObjReader reader;

        if (const tinyobj::ObjReaderConfig reader_config; !reader.ParseFromFile(path, reader_config)) {
            if (!reader.Error().empty()) {
                Logger::error("Failed to load %s because: %s", path.c_str(), reader.Error().c_str());
            }

            return;
        }

        if (!reader.Warning().empty()) {
            Logger::error("Warning in %s because: %s", path.c_str(), reader.Warning().c_str());
        }

        auto &attributes = reader.GetAttrib();
        auto &shapes = reader.GetShapes();
        auto &materials = reader.GetMaterials();

        for (const auto &shape: shapes) {
            for (const auto &index: shape.mesh.indices) {
                if (index.vertex_index >= 0) {
                    mesh->vertices.push_back(attributes.vertices[3 * index.vertex_index + 0]);
                    mesh->vertices.push_back(attributes.vertices[3 * index.vertex_index + 1]);
                    mesh->vertices.push_back(attributes.vertices[3 * index.vertex_index + 2]);
                } else {
                    mesh->vertices.push_back(0.0f);
                    mesh->vertices.push_back(0.0f);
                    mesh->vertices.push_back(0.0f);
                }

                if (index.normal_index >= 0) {
                    mesh->normals.push_back(attributes.normals[3 * index.normal_index + 0]);
                    mesh->normals.push_back(attributes.normals[3 * index.normal_index + 1]);
                    mesh->normals.push_back(attributes.normals[3 * index.normal_index + 2]);
                } else {
                    mesh->normals.push_back(0.0f);
                    mesh->normals.push_back(0.0f);
                    mesh->normals.push_back(0.0f);
                }

                if (index.texcoord_index >= 0) {
                    mesh->uvs.push_back(attributes.texcoords[2 * index.texcoord_index + 0]);
                    mesh->uvs.push_back(attributes.texcoords[2 * index.texcoord_index + 1]);
                } else {
                    mesh->uvs.push_back(0.0f);
                    mesh->uvs.push_back(0.0f);
                }

                if (!attributes.colors.empty() && index.vertex_index >= 0) {
                    mesh->colors.push_back(attributes.colors[3 * index.vertex_index + 0]);
                    mesh->colors.push_back(attributes.colors[3 * index.vertex_index + 1]);
                    mesh->colors.push_back(attributes.colors[3 * index.vertex_index + 2]);
                } else {
                    mesh->colors.push_back(1.0f);
                    mesh->colors.push_back(1.0f);
                    mesh->colors.push_back(1.0f);
                }

                mesh->indices.push_back(static_cast<unsigned int>(mesh->indices.size()));
            }
        }
    }
};
