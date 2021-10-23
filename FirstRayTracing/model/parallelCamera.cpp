#include "parallelCamera.h"

ray parallelCamera::get_ray(float u, float v) {
    point3d startPoint = position +(-horizontal/2) + (-vertical/2);
    return ray(startPoint + u*horizontal + v*vertical, direction);
}
