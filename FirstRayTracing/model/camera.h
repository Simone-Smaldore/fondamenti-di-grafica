#ifndef FIRSTRAYTRACING_CAMERA_H
#define FIRSTRAYTRACING_CAMERA_H

#include "../utilitySDL/utilitySDLInline.h"

class camera {


public:

    camera(point3d pos, point3d lookat, vec3 up, float vfov, float aspect) {
        float theta = vfov*M_PI / 180.0f; //RADIANTI
        float half_height = tan(theta / 2.0f);
        float half_width = half_height * aspect;
        position = pos;
        w = normalize(pos - lookat);
        u = normalize(cross(up, w));
        v = cross(w, u);
        left = -half_width*u - half_height*v - w;
        horizontal = 2.0f * half_width*u;
        vertical = 2.0f * half_height*v;
    }

    ray get_ray(float u, float v);

    point3d position;
    vec3 left;
    vec3 u, v, w;
    vec3 horizontal, vertical;

};


#endif //FIRSTRAYTRACING_CAMERA_H
