#include "camera.h"

ray camera::get_ray(float u, float v) {
    return ray(position, left + u*horizontal + v*vertical);
}
