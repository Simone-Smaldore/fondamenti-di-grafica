#pragma once
#include "utilitySDLInline.h"
#include "genericCamera.h"

class parallelCamera : public genericCamera {

public:

    parallelCamera(point3d pos, point3d lookat, vec3 up, float vfov, float aspect) {
        float theta = vfov * M_PI / 180.0f; //RADIANTI
        height = tan(theta / 2.0f) * 2.0f;
        width = height * aspect;
        lookPoint = lookat;
        position = pos;
        upVec = up;
        direction = lookat - pos;
        update_camera();
    }

    ray get_ray(float u, float v) override;

    void update_camera() override;

    point3d position;
    point3d lookPoint;
    vec3 left;
    vec3 upVec;
    vec3 u, v, w;
    vec3 horizontal, vertical;
    vec3 direction;
    float height, width;

};
