#pragma once

#include <sstream>
#include <iostream>
#include <cmath>
using namespace std;

struct vec3 {
    float x, y, z;

    vec3() = default;

    vec3(float a, float b, float c) {
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

    vec3& operator*=(float s) {
        x *= s;
        y *= s;
        z *= s;
        return (*this);
    }

    vec3& operator+=(const vec3& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return (*this);
    }

    vec3& operator-=(const vec3& v) {
        x -= v.x;
        y -= v.y;
        z -= v.z;
        return (*this);
    }

};

inline vec3 operator*(const vec3& v, float s) {
    return (vec3(v.x * s, v.y * s, v.z * s));
}

inline vec3 operator*(float s, const vec3& v) {
    return (vec3(v.x * s, v.y * s, v.z * s));
}

inline vec3 operator/(const vec3& v, float s) {
    s = 1.0f / s;
    return (vec3(v.x * s, v.y * s, v.z * s));
}

inline vec3 operator-(const vec3& v) {
    return (vec3(-v.x, -v.y, -v.z));
}

inline float magnitude(const vec3& v) {
    return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

inline vec3 normalize(const vec3& v) {
    return (v / magnitude(v));
}

inline vec3 operator+(const vec3& a, const vec3& b) {
    return (vec3(a.x + b.x, a.y + b.y, a.z + b.z));
}

inline vec3 operator-(const vec3& a, const vec3& b) {
    return (vec3(a.x - b.x, a.y - b.y, a.z - b.z));
}

inline float dot(const vec3& a, const vec3& b) {
    return (a.x * b.x + a.y * b.y + a.z * b.z);
}

inline vec3 cross(const vec3& a, const vec3& b) {
    return (vec3(a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x));
}

inline string toString(const vec3& v) {
    stringstream ss;
    ss << "VECTOR(" << v.x << ", " << v.y << ", " << v.z << ")";
    string s = ss.str();
    return s;
}

inline vec3 reflect(const vec3& i, const vec3& n){
    return  2.0f * dot(i, n) * n - i; 
}
