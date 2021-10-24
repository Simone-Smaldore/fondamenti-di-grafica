#include "camera.h"

ray camera::get_ray(float u, float v) {
    return ray(position, left + u * horizontal + v * vertical);
}

void camera::update_camera() {
    w = normalize(position - lookPoint);
    u = normalize(cross(upVec, w));
    v = cross(w, u);
    left = -(width / 2.0f) * u - (height / 2.0f) * v - w;
    horizontal = 2.0f * (width / 2.0f) * u;
    vertical = 2.0f * (height / 2.0f) * v;
}
