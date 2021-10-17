#ifndef FIRSTSDL_RAYTRACING_H
#define FIRSTSDL_RAYTRACING_H

#include "../utilitySDL/utilitySDLInline.h"
#include "../model/Object.h"
#include "../model/object_list.h"

vec3 getColor(object_list* scene, ray &r, vec3 &startColor, vec3 &endColor, float t_min = 0, float t_max = FLT_MAX);

void showRayTracing();


#endif //FIRSTSDL_RAYTRACING_H
