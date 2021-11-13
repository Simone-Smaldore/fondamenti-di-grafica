#pragma once

#include "vec3.h"
#include "point3d.h"
#include "ray.h"
#include "SDL.h"
#include "color.h"

using namespace std;

inline void setColor(SDL_Renderer*& renderer, float r, float g, float b, float a = 1.0) {
    r = (r > 1.0f) ? 1.0f : ((r < 0.0f) ? 0.0f : r);
    g = (g > 1.0f) ? 1.0f : ((g < 0.0f) ? 0.0f : g);
    b = (b > 1.0f) ? 1.0f : ((b < 0.0f) ? 0.0f : b);
    a = (a > 1.0f) ? 1.0f : ((a < 0.0f) ? 0.0f : a);
    SDL_SetRenderDrawColor(renderer, Uint8(r * 255.0), Uint8(g * 255.0), Uint8(b * 255.0), Uint8(a * 255.0));
}

inline void setPixel(SDL_Renderer*& renderer, int x, int y, float ny) {
    SDL_RenderDrawPoint(renderer, x, ny - y - 1);
}

inline void setPixel(SDL_Renderer*& renderer, int x, int y, float r, float g, float b, float ny, float a = 1.0) {
    setColor(renderer, r, g, b, a);
    setPixel(renderer, x, y, ny);
}

inline void drawLine(SDL_Renderer*& renderer, int x1, int y1, int x2, int y2, int ny) {
    SDL_RenderDrawLine(renderer, x1, ny - y1 - 1, x2, ny - y2 - 1);
}

inline float lerp(float a, float b, float t) {
    return a + (b - a) * t;
}

inline vec3 lerp(const vec3& a, const vec3& b, float t) {
    return vec3(lerp(a.x, b.x, t),
        lerp(a.y, b.y, t),
        lerp(a.z, b.z, t));
}

inline color lerp(const color& a, const color& b, float t) {
    return color(lerp(a.r, b.r, t),
        lerp(a.g, b.g, t),
        lerp(a.b, b.b, t));
}

inline bool hit_sphere(const point3d& sphereCenter, float sphereRadius, const ray& r) {
    vec3 oc = r.origin() - sphereCenter;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

inline float get_hit_sphere_t_value(const point3d& sphereCenter, float sphereRadius, const ray& r) {
    vec3 oc = r.origin() - sphereCenter;
    float a = dot(r.direction(), r.direction());
    float b = 2.0 * dot(oc, r.direction());
    float c = dot(oc, oc) - sphereRadius * sphereRadius;
    float discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return -1.0;
    else {
        return (-b - sqrt(discriminant)) / (2.0f * a);
    }
}

inline vec3 colorLerp(float unit_direction, vec3& startColor, vec3& endColor) {
    float t = 0.5f * (unit_direction + 1.0f);
    return lerp(startColor, endColor, t);
}

inline color colorLerp(float unit_direction, const color& startColor, const color& endColor) {
    float t = 0.5f * (unit_direction + 1.0f);
    return lerp(startColor, endColor, t);
}


inline vec3 colorLerpX(ray& r, vec3& startColor, vec3& endColor) {
    vec3 unit_direction = normalize(r.direction());
    return colorLerp(unit_direction.x, startColor, endColor);
}

inline vec3 colorLerpY(ray& r, vec3& startColor, vec3& endColor) {
    vec3 unit_direction = normalize(r.direction());
    return colorLerp(unit_direction.y, startColor, endColor);
}

inline color colorLerpY(const ray& r, const color& startColor, const color& endColor) {
    vec3 unit_direction = normalize(r.direction());
    return colorLerp(unit_direction.y, startColor, endColor);
}

inline vec3 colorLerpZ(ray& r, vec3& startColor, vec3& endColor) {
    vec3 unit_direction = normalize(r.direction());
    return colorLerp(unit_direction.z, startColor, endColor);
}

inline bool isInfinitesimalNumber(float f) {
    if (abs(f) < 0.0001) {
        return true;
    }
    return false;
}

inline float randZeroToOne() {
    return ((float)rand()) / (float)RAND_MAX;
}
