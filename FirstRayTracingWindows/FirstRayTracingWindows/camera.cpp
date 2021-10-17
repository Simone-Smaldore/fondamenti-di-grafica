#include "camera.h"

ray camera::get_ray(float s, float t) {
    float u = left + s * horizontal;
    float v = bottom + t * vertical;
    return ray(origin, u * un + v * vn - d * wn);
}

