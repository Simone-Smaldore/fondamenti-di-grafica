#pragma once

#include <sstream>

using namespace std;

struct point3d {
    float x, y, z;

    point3d() = default;

    point3d(float a, float b, float c) {
        x = a;
        y = b;
        z = c;
    }

    float& operator[](int i) {
        return ((&x)[i]);
    }

    const float& operator[](int i) const {
        return ((&x)[i]);
    }
};

inline vec3 operator-(const point3d& a, const point3d& b) {
    return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline point3d operator+(const point3d& a, const vec3& b) {
    return (point3d(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline point3d operator+(const vec3& b, const point3d& a) {
    return (point3d(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline string toString(const point3d& p) {
    stringstream ss;
    ss << "POINT(" << p.x << ", " << p.y << ", " << p.z << ")";
    string s = ss.str();
    return s;
}