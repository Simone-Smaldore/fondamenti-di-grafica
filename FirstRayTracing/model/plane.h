#ifndef FIRSTRAYTRACING_PLANE_H
#define FIRSTRAYTRACING_PLANE_H


#include "Object.h"
#include "../utilitySDL/utilitySDLInline.h"

class plane : public Object {
public:
    point3d p0;
    vec3 normal;

    plane() {};
    plane(point3d c, vec3 n) : p0(c), normal(n){
        color = vec3(0.0, 0.0,0.0);
    };

    bool hit_object(const ray& ray, float t_min, float t_max, hit_record& rec) override;
    string toString() override;
};

#endif //FIRSTRAYTRACING_PLANE_H
