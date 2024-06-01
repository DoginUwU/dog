#include "frustum/frustum.hpp"

#include <iostream>

namespace Dog
{
    Frustum::Frustum(const glm::mat4 viewProjection)
    {
        frustrate(viewProjection);
    }

    Frustum::~Frustum()
    {
        for (int i = 0; i < 6; i++)
        {
            delete planes[i];
        }
    }

    void Frustum::frustrate(const glm::mat4 viewProjection)
    {
        glm::mat4 clip = glm::transpose(viewProjection);

        planes[0] = new Plane(clip[3] + clip[0]);
        planes[1] = new Plane(clip[3] - clip[0]);
        planes[2] = new Plane(clip[3] + clip[1]);
        planes[3] = new Plane(clip[3] - clip[1]);
        planes[4] = new Plane(clip[3] + clip[2]);
        planes[5] = new Plane(clip[3] - clip[2]);

        for (const auto & plane : planes)
        {
            plane->normalize();
        }
    }

    bool Frustum::pointInFrustum(const glm::vec3 point, const float radius) const
    {
        for (const auto plane : planes)
        {
            if (plane->distance(point) <= -radius)
            {
                return false;
            }
        }

        return true;
    }

    bool Frustum::aabbInFrustum(const AABB *aabb) const
    {
        for (const auto plane : planes)
        {
            auto extent = glm::vec3(0.0f);

            extent.x = plane->quaternion.x >= 0 ? aabb->max.x : aabb->min.x;
            extent.y = plane->quaternion.y >= 0 ? aabb->max.y : aabb->min.y;
            extent.z = plane->quaternion.z >= 0 ? aabb->max.z : aabb->min.z;

            if (plane->distance(extent) < 0)
            {
                return false;
            }
        }

        return true;
    }
}
