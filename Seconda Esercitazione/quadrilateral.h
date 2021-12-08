#pragma once
#include "Object.h"
#include "utilitySDLInline.h"


class quadrilateral : public Object {
public:
    point3d p0;
    vec3 side1;
    vec3 side2;

    quadrilateral() {};
    quadrilateral(point3d c, vec3 s1, vec3 s2) : p0(c), side1(s1), side2(s2) {
        
    }

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    bool hit_shadow(const ray& ray, float t_min, float t_max) override;
    string toString();
};