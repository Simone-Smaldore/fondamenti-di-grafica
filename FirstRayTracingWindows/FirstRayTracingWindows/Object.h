#pragma once

#include "utilitySDLInline.h"
#include <list>

struct hit_record {
    float t;
    point3d p;
    vec3 normal;
    int object_index;
};

class Object {
public:
    virtual bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) = 0;
    virtual string toString() = 0;
    vec3 color;
};