#ifndef FIRSTRAYTRACING_TRIANGLE_H
#define FIRSTRAYTRACING_TRIANGLE_H

#include "Object.h"
#include "../utilitySDL/utilitySDLInline.h"

class triangle : public Object {
public:
    point3d p1;
    point3d p2;
    point3d p3;

    triangle() {};
    triangle(point3d p1, point3d p2, point3d p3) : p1(p1), p2(p2), p3(p3){
        color = vec3(0.0, 0.0,0.0);
    };

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    string toString() override;
};

#endif //FIRSTRAYTRACING_TRIANGLE_H
