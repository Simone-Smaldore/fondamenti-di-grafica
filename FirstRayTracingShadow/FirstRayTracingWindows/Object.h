#pragma once

#include "utilitySDLInline.h"
#include <list>
#include "material.h"

struct hit_record {
    float t;
    point3d p;
    vec3 normal;
    int object_index;
    material m;
};

class Object {
public:
    material mat;

    void setMaterial(material& m) {
        mat = m;
    }

    virtual bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) = 0;
    virtual string toString() = 0;
    vec3 color;

};