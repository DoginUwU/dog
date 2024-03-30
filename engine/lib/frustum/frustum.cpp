#include "frustum/frustum.hpp"

#include <iostream>

namespace Dog
{
    Frustum::Frustum(glm::mat4 viewProjection)
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

    void Frustum::frustrate(glm::mat4 viewProjection)
    {
        glm::mat4 clip = glm::transpose(viewProjection);

        planes[0] = new Plane(clip[3] + clip[0]);
        planes[1] = new Plane(clip[3] - clip[0]);
        planes[2] = new Plane(clip[3] + clip[1]);
        planes[3] = new Plane(clip[3] - clip[1]);
        planes[4] = new Plane(clip[3] + clip[2]);
        planes[5] = new Plane(clip[3] - clip[2]);

        for (int i = 0; i < 6; i++)
        {
            planes[i]->normalize();
        }
    }

    bool Frustum::pointInFrustum(glm::vec3 point, float radius)
    {
        for (int i = 0; i < 6; i++)
        {
            if (planes[i]->distance(point) <= -radius)
            {
                return false;
            }
        }

        return true;
    }

    bool Frustum::aabbInFrustum(AABB *aabb)
    {
        glm::vec3 *corners = aabb->corners;

        for (int i = 0; i < 6; i++)
        {
            glm::vec3 extent = glm::vec3(0.0f);

            extent.x = planes[i]->quaternion.x >= 0 ? aabb->max.x : aabb->min.x;
            extent.y = planes[i]->quaternion.y >= 0 ? aabb->max.y : aabb->min.y;
            extent.z = planes[i]->quaternion.z >= 0 ? aabb->max.z : aabb->min.z;

            if (planes[i]->distance(extent) < 0)
            {
                return false;
            }
        }

        return true;
    }
}
