#pragma once
#include <glm/glm.hpp>

class Vector3F {
public:
    // TODO: Make my only math library
    glm::vec3 data;

    Vector3F() : data(0.0f, 0.0f, 0.0f) {
    }

    Vector3F(const float x, const float y, const float z) : data(x, y, z) {
    }

    Vector3F(const double x, const double y, const double z) : data(x, y, z) {
    }

    explicit Vector3F(const glm::vec<3, float> value) : data(value) {
    }

    [[nodiscard]] float x() const { return data.x; }
    [[nodiscard]] float y() const { return data.y; }
    [[nodiscard]] float z() const { return data.z; }

    static Vector3F normalize(const Vector3F &value) {
        const auto new_data = glm::normalize(value.data);

        return Vector3F{new_data};
    }

    static Vector3F cross(const Vector3F &x, const Vector3F &y) {
        const auto new_data = glm::cross(x.data, y.data);

        return Vector3F{new_data};
    }

    static float radians(const float value) {
        return glm::radians(value);
    }

    Vector3F operator+(const Vector3F &other) const {
        Vector3F result;
        result.data = data + other.data;

        return result;
    }

    Vector3F operator*(const Vector3F &other) const {
        Vector3F result;
        result.data = data * other.data;

        return result;
    }

    Vector3F operator*(const float &other) const {
        Vector3F result;
        result.data = data * other;

        return result;
    }

    Vector3F operator+=(const Vector3F &other) {
        this->data += other.data;

        return *this;
    }

    Vector3F operator-=(const Vector3F &other) {
        this->data -= other.data;

        return *this;
    }
};
