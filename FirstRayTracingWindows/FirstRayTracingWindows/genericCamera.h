#pragma once
#include "utilitySDLInline.h"

class genericCamera {
public:
    virtual ray get_ray(float u, float v) = 0;
    virtual void update_camera() = 0;
};
