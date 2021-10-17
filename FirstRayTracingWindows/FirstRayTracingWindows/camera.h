#pragma once
#include "utilitySDLInline.h"

class camera {

public:

    camera() {
        left = -2.0;
        right = 2.0;
        bottom = -1.0;
        top = 1.0;
        origin = point3d(0.0, 0.0, 0.0);
        un = vec3(1.0, 0.0, 0.0);
        vn = vec3(0.0, 1.0, 0.0);
        wn = vec3(0.0, 0.0, 1.0);
        d = 1.0;
        horizontal = right - left;
        vertical = top - bottom;
    }

    ray get_ray(float s, float t);

    point3d origin;
    float left, right, bottom, top;
    float d;
    vec3 un, vn, wn;
    float horizontal, vertical;

};