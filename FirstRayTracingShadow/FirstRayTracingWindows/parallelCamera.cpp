#include "parallelCamera.h"

ray parallelCamera::get_ray(float u, float v) {
    point3d startPoint = position + (-horizontal / 2) + (-vertical / 2);
    return ray(startPoint + u * horizontal + v * vertical, direction);
}

void parallelCamera::update_camera() {
    w = normalize(position - lookPoint);
    u = normalize(cross(upVec, w));
    v = cross(w, u);
    left = -(width / 2.0f) * u - (height / 2.0f) * v - w;
    horizontal = 2.0f * (width / 2.0f) * u;
    vertical = 2.0f * (height / 2.0f) * v;
    direction = lookPoint - position;
}