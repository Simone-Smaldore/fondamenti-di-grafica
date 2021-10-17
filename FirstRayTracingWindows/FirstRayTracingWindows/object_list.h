#pragma once
#include "Object.h"

class object_list {
public:
    object_list() {}

    object_list(Object** l, int n) {
        list = l;
        list_size = n;
    }

    bool trace_ray(const ray& r, float tmin, float tmax, hit_record& rec) const;

    Object** list;
    int list_size;
};
