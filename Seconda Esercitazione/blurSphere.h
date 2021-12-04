#pragma once

#include "Object.h"
#include "utilitySDLInline.h"

class blurSphere : public Object {
public:
    point3d centerStart;
    point3d centerEnd;
    float timeStart;
    float timeEnd;
    float radius;


    blurSphere() {};
    blurSphere(point3d c1, point3d c2, float t1, float t2, float r) : centerStart(c1), centerEnd(c2), timeStart(t1), timeEnd(t2), radius(r) {

    };

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    bool hit_shadow(const ray& ray, float t_min, float t_max) override;
    point3d move_sphere(float time) const;

};


