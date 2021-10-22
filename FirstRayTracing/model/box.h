#ifndef FIRSTRAYTRACING_BOX_H
#define FIRSTRAYTRACING_BOX_H

#include "Object.h"
#include "../utilitySDL/utilitySDLInline.h"


class box : public Object {
public:
    point3d pMin;
    vec3 side1;
    vec3 side2;
    vec3 side3;

    box() {};
    box(point3d c, vec3 s1, vec3 s2, vec3 s3) : pMin(c), side1(s1), side2(s2), side3(s3){
        color = vec3(0.0, 0.0,0.0);
    };

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    string toString() override;
};


#endif //FIRSTRAYTRACING_BOX_H
