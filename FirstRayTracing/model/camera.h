#ifndef FIRSTRAYTRACING_CAMERA_H
#define FIRSTRAYTRACING_CAMERA_H

#include "../utilitySDL/utilitySDLInline.h"

class camera {

public:

    camera(point3d pos, point3d lookat, vec3 up, float vfov, float aspect) {
        float theta = vfov*M_PI / 180.0f; //RADIANTI
        height = tan(theta / 2.0f) * 2.0f;
        width = height * aspect * 2.0f;
        lookPoint = lookat;
        position = pos;
        upVec = up;
        update_camera();
    }

    ray get_ray(float u, float v);

    void update_camera();

    point3d position;
    point3d lookPoint;
    vec3 left;
    vec3 upVec;
    vec3 u, v, w;
    vec3 horizontal, vertical;
    float height, width;

};


#endif //FIRSTRAYTRACING_CAMERA_H
