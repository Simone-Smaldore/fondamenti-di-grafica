#pragma once
#include "utilitySDLInline.h"
#include "material.h"

struct hit_record {
    float t;
    point3d p;
    vec3 normal;
    material m;
    float u;
    float v;
};