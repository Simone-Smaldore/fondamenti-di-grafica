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

    Sphere(point3d cen, float r, material* m) {
        center = cen;
        radius = r;
        mat = *m;
    }

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    string toString() override;
};

