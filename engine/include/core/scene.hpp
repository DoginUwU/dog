#pragma once
#include <vector>
#include <memory>

#include "object.hpp"

class Scene : public Object {
public:
    void add_object(std::unique_ptr<Object> object);

    void update() override;

    ~Scene() override = default;

private:
    std::vector<std::unique_ptr<Object> > active_objects;
};
