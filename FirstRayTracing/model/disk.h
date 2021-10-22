#ifndef FIRSTRAYTRACING_DISK_H
#define FIRSTRAYTRACING_DISK_H

#include "Object.h"
#include "../utilitySDL/utilitySDLInline.h"

class disk : public Object {
public:
    point3d p0;
    vec3 normal;
    float rayDistance;

    disk() {};

    disk(point3d c, vec3 n, float rd) : p0(c), normal(n), rayDistance(rd){
        color = vec3(0.0, 0.0,0.0);
    };

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    string toString() override;
};


#endif //FIRSTRAYTRACING_DISK_H
