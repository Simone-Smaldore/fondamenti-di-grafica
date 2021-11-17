#pragma once

#include "Object.h"
#include "utilitySDLInline.h"

class Sphere : public Object {
public:
    point3d center;
    float radius;

    Sphere() {};
    Sphere(point3d c, float r) : center(c), radius(r) {
        color = vec3(0.0, 0.0, 0.0);
    };

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    bool hit_shadow(const ray& ray, float t_min, float t_max) override;
    string toString();
};

