#pragma once

#include "utilitySDLInline.h"
#include "record.h"
#include <list>


class Object {
public:

    virtual bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) = 0;
    virtual bool hit_shadow(const ray& r, float t_min, float t_max) = 0;
};