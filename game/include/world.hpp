#pragma once

#include <memory>

#include "chunk.hpp"
#include "core/object.hpp"

class World final : public Object {
public:
    void start() override {
        for (unsigned x = 0; x < 10; ++x) {
            for (unsigned z = 0; z < 10; ++z) {
                GameManager::active_scene->add_object(std::make_unique<Chunk>(Vector3F{x, 0, z}));
            }
        }
    }

    void update(float delta_time) override {
    }

    ~World() override = default;

private:
    //std::vector<std::unique_ptr<Chunk> > chunks;
};
