#pragma once

#include "utilitySDLInline.h"
#include "material.h"
#include <list>

struct hit_record {
    float t;
    point3d p;
    vec3 normal;
    material m;
};

class Object {
public:

    virtual bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) = 0;
    virtual bool hit_shadow(const ray& r, float t_min, float t_max) = 0;
    vec3 color;

};